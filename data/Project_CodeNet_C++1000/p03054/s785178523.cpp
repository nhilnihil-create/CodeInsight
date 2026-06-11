#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll h,w,n;
ll sr,sc;
string s,t;

vector<ll>dpr,dpl,dpu,dpd;

void input(){
    cin >> h >> w >> n;
    cin >> sr >> sc;
    cin >> s >> t;
}

void initial(){
    dpr.resize(n+1,INF);
    dpl.resize(n+1,-1);
    dpu.resize(n+1,-1);
    dpd.resize(n+1,INF);
}

void ex(){
    cout << "NO" << endl;
    exit(0);
}

int main(){
    input();
    initial();
    for(int i=n-1;i>=0;i--){
        //right
        dpr[i]=dpr[i+1];
        if(t[i]=='L')dpr[i]++;
        if(s[i]=='R')chmin(dpr[i],min(dpr[i]-1,w));
        //left
        dpl[i]=dpl[i+1];
        if(t[i]=='R')dpl[i]--;
        if(s[i]=='L')chmax(dpl[i],max(1LL,dpl[i]+1));
        //up
        dpu[i]=dpu[i+1];
        if(t[i]=='D')dpu[i]--;
        if(s[i]=='U')chmax(dpu[i],max(1LL,dpu[i]+1));
        //down
        dpd[i]=dpd[i+1];
        if(t[i]=='U')dpd[i]++;
        if(s[i]=='D')chmin(dpd[i],min(dpd[i]-1,h));
        if(dpr[i]==1||dpl[i]==w||dpu[i]==h||dpd[i]==1)ex();
    }
    bool ans = false;
    if(dpr[0]<=sc||dpl[0]>=sc)ans=true;
    if(dpu[0]>=sr||dpd[0]<=sr)ans=true;
    if(ans)cout<<"NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

