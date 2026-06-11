//ID

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, ll>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,m;cin>>n>>m;
    vector<vector<p>>p(n+1);
    rep(i,0,m){
        int pp,y;cin>>pp>>y;
        p[pp].pb(mp(y,i));
    }
    vector<tuple<int,int,int>>ans;
    rep(i,0,n+1){
        if(!p[i].empty()){
            sort(range(p[i]));
            ll t = 1;
            for(auto j:p[i]){
                ans.pb(make_tuple(j.second,i,t));
                t++;
            }
        }
    }
    sort(range(ans));
    rep(i,0,m){
        int a,b;
        a=get<1>(ans[i]);b=get<2>(ans[i]);
        printf("%06d%06d\n",a,b);
    }
    return 0;
}