//Handstand 

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
    int n,k;string s;cin>>n>>k>>s;
    deque<char>a;
    int t=0,ans=0;
    bool l=true;
    rep(i,0,n){
        if(s[i]=='0'&&l){
            t++;
            l=false;
        }else if(s[i]=='1')l=true;;
        if(t>k){
            while(a.front()=='1')a.pop_front();
            while(a.front()=='0')a.pop_front();
            t--;
        }
        a.pb(s[i]);
        ans=max(ans,(int)a.size());
    }
    cout<<ans<<nnn;
    return 0;
}