#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    ll n,m;cin>>n>>m;
    ll ans=-1;
    rep(i,sqrt(m)+1){
        if(i==0)continue;
        if(m%i==0&&i*n<=m){
            ans =max(ans,(ll)i);
        }
        if(m%i==0&&(m/i)*n<=m){
            ans =max(ans,m/i);
        }
        
    }
    cout<<ans<<endl;
}