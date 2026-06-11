//Limited Insertion

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
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    nvarep(n,b);
    vector<int>ans(n);
    rep(i,0,n){
        for(int j=b.size()-1;j>=-1;j--){
            if(j==-1){
                cout<<-1<<nnn;
                return 0;
            }else if(b[j]==j+1){
                ans[n-1-i]=b[j];
                b.erase(b.begin()+j);
                break;
            }
        }
    }
    rep(i,0,n)cout<<ans[i]<<nnn;
    return 0;
}