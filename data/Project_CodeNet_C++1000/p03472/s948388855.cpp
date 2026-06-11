//Katana Thrower

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,h;cin>>n>>h;
    int k=0;
    priority_queue<int>q;
    rep(i,0,n){
        int a,b;cin>>a>>b;
        k=max(k,a);
        q.push(b);
    }
    int ans=0;
    if(k>=q.top()){
        ans=ceil((double)h/(double)k);
    }else{
        while(q.top()>k&&!q.empty()&&h>0){
            h-=q.top();
            q.pop();
            ans++;
        }
        if(h>0)ans+=ceil((double)h/(double)k);
    }
    cout<<ans<<nnn;
    return 0;
}