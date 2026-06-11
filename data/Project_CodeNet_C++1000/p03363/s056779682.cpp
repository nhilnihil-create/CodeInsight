#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    
   int n;
   cin>>n;
   vector<ll> A(n), sum(n+1, 0);
   rep(i,n){
       cin>>A[i];
       sum[i+1] = sum[i] + A[i];
   }
   sort(sum.begin(), sum.end());
    
    map<ll, ll> mp;
   for(auto s:sum){
    //    cout<<s<<" ";
       mp[s]++;
   }
//    cout<<endl;
    ll ans=0;
    for(auto m:mp){
        ans+=m.second*(m.second-1)/2;
    }
    
    cout<<ans<<endl;

    return 0;
}
