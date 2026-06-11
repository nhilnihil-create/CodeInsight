#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<vector<ll> >G(n+1);
    rep(i,n-1){
        ll a,b;cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll ans=0;
    vector<ll> c(n);
    rep(i,n){
        cin>>c[i];
        ans+=c[i];
    }
    sort(all(c));
    reverse(all(c));
    ans-=c[0];
    queue<ll>q;
    q.push(1);
    vector<ll>visited(n+1);
    vector<ll>d(n+1);
    ll now=0;
    while(!q.empty()){
        ll k=q.front();
        visited[k]=1;
        d[k]=c[now];
        q.pop();
        for(auto e:G[k]){
            if(visited[e])continue;
            else q.push(e);
        }
        now++;
    }
    cout<<ans<<endl;
    REP(i,1,n+1){
        cout<<d[i]<<' ';
    }
    cout<<endl;
}