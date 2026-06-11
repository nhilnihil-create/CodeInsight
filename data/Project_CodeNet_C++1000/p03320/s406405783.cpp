#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    vector<ll> ans;
    ll s=1e15-1;

    auto g=[](ll num){
        long double ret=num;
        long double bo=0;
        while(num){
            bo+=num%10;
            num/=10;
        }
        return ret/bo;
    };

    function<void(ll)> dfs=[&](ll num){
        ans.push_back(num);
        int d=0;
        ll tmp=num;
        while(tmp) d++,tmp/=10;
        d--;
        ll m=1;
        rep(i,d-5) m*=10;
        
        while(m<num){
            if(g(num-m)<=g(num)){
                dfs(num-m);
                break;
            }
            m*=10;
        }
    };
    dfs(s);
    sort(ALL(ans));
    int k;cin>>k;
    rep(i,k) cout<<ans[i]<<endl;
    return 0;
}
