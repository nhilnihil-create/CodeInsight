//4/N

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
    rep(i,1,3501)rep(j,1,3501){
        double a=4*i*j-n*j-n*i;
        double b=n*i*j;
        if(a==0)continue;
        double u=b/a;
        int t=ceil(u);
        if(t<1||t>3501)continue;
        if(t==u){
            cout<<i<<spa<<j<<spa<<t<<nnn;
            return 0;
        }
    }
    return 0;
}