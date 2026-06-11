//Integer Cards

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
    priority_queue<int,vector<int>,greater<int>>a;
    rep(i,0,n){
        int c;cin>>c;
        a.push(c);
    }
    vector<p>memo;
    priority_queue<int>yo;
    rep(i,0,m){
        int b,c;cin>>b>>c;
        memo.pb(mp(c,b));
    }
    sort(range(memo));
    for(int i=memo.size()-1;i>=0;i--){
        int b=memo[i].second,c=memo[i].first;
        if(yo.size()>n)break;
        rep(i,0,b){
            yo.push(c);
            if(yo.size()>n)break;
        }
    }
    int ans = 0;
    while(!a.empty()){
        int c = a.top();
        a.pop();
        if(yo.empty()||c>=yo.top()){
            ans+=c;
        }else{
            ans+=yo.top();
            yo.pop();
        }
    }
    cout<<ans<<nnn;
    return 0;
}