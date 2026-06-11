#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);



void solve(int T){
   double n,k;
   cin>>n>>k;
   double ans=0.0;
   //cout<<(ld)1/n<<"\n";
   for(int i=1;i<=n;i++){
        ll x=i;
        ld tmp=1.0/n;
        while(x<k){
            tmp*=(1.0/2.0);
            x*=2;
        }
        ans+=tmp;
   }
   cout<<fixed<<setprecision(12)<<ans<<"\n";
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}



