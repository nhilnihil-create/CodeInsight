#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int N,D[50];
int cnt[13],vis[24];

int count(){
    int mi=INF;
    REP(i,24) REP(j,24) if(vis[i] && vis[j] && i!=j){
        int d1=abs(i-j);
        int d2=24-d1;
        int d=min(d1,d2);
        mi = min(mi,d);
    }
    return mi;
}

int solve(){
    REP(i,N) cnt[D[i]]++;
    if(cnt[0]) return 0;
    vis[0]=1;
    vector<int> v;
    for(int i=1;i<12;i++){
        if(cnt[i]==1) v.push_back(i);
        else if(cnt[i]==2) vis[i]=vis[24-i]=1;
        else if(2<cnt[i]) return 0;
    }
    if(cnt[12]==1) vis[12]=1;
    else if(2<=cnt[12]) return 0;

    int M=v.size();
    if(M==0) return count();

    int ans=0;
    REP(mask,1<<M){
        REP(i,M){
            if(mask&(1<<i)) vis[v[i]]=1,vis[24-v[i]]=0;
            else vis[v[i]]=0,vis[24-v[i]]=1;
        }
        ans=max(ans,count());
    }
    return ans;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    REP(i,N) cin>>D[i];
    cout<<solve()<<endl;
}