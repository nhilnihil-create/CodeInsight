#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main() {
   ll n,ans=0;
   cin>>n;
  
   ll a[n],b[n],c[n];
   rep(i,n)cin>>a[i];
   
   
   rep(i,n)cin>>b[i];
   
   
   rep(i,n)cin>>c[i];
   
   sort(a,a+n);
   sort(c,c+n);
   
   rep(i,n){
       ll ans1,ans2;
       ans1 = lower_bound(a,a+n,b[i])-a;
       ans2 = upper_bound(c,c+n,b[i])-c; 
       //cout<<ans1<<" "<<ans2<<endl;
       if(ans1>n)ans1--;
       if(ans2>n)ans2--;
       ans+=(ans1)*(n-ans2);
       
   }
   cout<<ans<<endl;
   
   
   
   
}

