//Zero-Sum Ranges

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
    nvarep(n,a);
    vector<int>t(n+1,0);
    rep(i,0,n)t[i+1]=t[i]+a[i];
    sort(range(t));
    map<int,int>m;
    rep(i,0,n+1)m[t[i]]++;
    int ans{};
    for(auto i:m)rep(j,1,i.second)ans+=j;
    cout<<ans<<nnn;
    return 0;
}