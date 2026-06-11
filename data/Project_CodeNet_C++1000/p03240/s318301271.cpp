//Pyramid

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
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vector<int>x,y,h;
    rep(i,0,n){
        int a,b,c;cin>>a>>b>>c;
        if(c!=0)x.pb(a),y.pb(b),h.pb(c);
    }
    n=x.size();
    rep(i,0,101)rep(j,0,101){
        int r=h[0]+abs(i-x[0])+abs(j-y[0]);
        bool flag=true;
        rep(k,1,n){
            if(r!=h[k]+abs(i-x[k])+abs(j-y[k]))flag=false;
        }
        if(x.size()>1&&flag){
            cout<<i<<spa<<j<<spa<<r<<nnn;
            return 0;
        }
    }
    rep(i,0,n){
        if(h[i]>0)cout<<x[i]<<spa<<y[i]<<spa<<h[i]<<nnn;
    }
    return 0;
}