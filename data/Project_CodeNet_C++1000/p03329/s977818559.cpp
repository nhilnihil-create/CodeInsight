//Strange Bank

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
    vector<int>a;
    a.pb(1);
    int t=6;
    a.pb(t);
    rep(i,0,5){
        t*=6;
        a.pb(t);
    }
    t=9;
    a.pb(t);
    rep(i,0,4){
        t*=9;
        a.pb(t);
    }
    sort(range(a),greater<int>());
    vector<int>m(n+1,inf);
    m[0]=0;
    rep(i,1,n+1){
        for(auto j:a){
            if(i-j<0)continue;
            m[i]=min(m[i],m[i-j]+1);
        }
    }
    cout<<m[n]<<nnn;
    return 0;
}