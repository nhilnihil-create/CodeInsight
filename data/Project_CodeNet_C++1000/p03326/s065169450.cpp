#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<vector<ll>> x(n,vector<ll>(3));
    rep(i,n)rep(j,3) cin>>x[i][j];
    ll res=0;
    for(int tmp=0;tmp<(1<<3);tmp++){
        bitset<3> s(tmp);
        priority_queue<ll> que;
        ll ans=0;
        rep(i,n){
            ll now=0;
            rep(j,3) if(s[j]==0)now-=x[i][j];else now+=x[i][j];
            que.push(now);
        }
        rep(i,m){
            ans+=que.top();que.pop();
        }
        res=max(ans,res);
    }
    cout<<res<<endl;
    return 0;
}
