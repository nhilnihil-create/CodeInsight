//Bridge

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,m;cin>>n>>m;
    vector<p>q(m);
    rep(i,0,m){
        cin>>q[i].first>>q[i].second;
        q[i].first--;
        q[i].second--;
    }
    int ans = 0;
    stack<int>t;
    rep(i,0,m){
        graph g(n);
        rep(j,0,m){
            if(i==j)continue;
            g[q[j].first].pb(q[j].second);
            g[q[j].second].pb(q[j].first);
        }
        t.push(0);
        vector<bool>s(n,false);
        
        while(!t.empty()){
            int v=t.top();
            t.pop();
            s[v]=true;
            
            rep(j,0,g[v].size())if(!s[g[v][j]])t.push(g[v][j]);
        }
        rep(j,0,n){
            if(!s[j]){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<nnn;
    return 0;
}