#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define p pair<vector<int>,int>
#define PP pair<P,P>
using namespace std;
vector<int> bom;
vector<int> con;
int n,a,b,c,ans;

void solve(int now, P f, P s, P t){
    if(now==n){
        if(f.second==0 || s.second==0 || t.second==0) return;
        int mp=abs(f.first-a)+abs(s.first-b)+abs(t.first-c)+10*(f.second-1+s.second-1+t.second-1);
        ans=min(ans,mp);
        return;
    }
    solve(now+1,f,s,t);
    solve(now+1,P(f.first+bom[now],f.second+1),s,t);
    solve(now+1,f,P(s.first+bom[now],s.second+1),t);
    solve(now+1,f,s,P(t.first+bom[now],t.second+1));
}

int main(){
    cin >> n >> a >> b >> c;
    rep(i,n){
        int l; cin >> l;
        bom.push_back(l);
    }

    ans=INF;
    solve(0,P(0,0),P(0,0),P(0,0));
    cout << ans << endl;
return 0;
}
