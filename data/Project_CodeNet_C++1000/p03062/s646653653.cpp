/*
   Push yourself, because no one else is going to do it for you.
*/
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long int
#define PI 2 * acos(0.0)
#define MAX 10000000000000000
#define in(a) scanf("%d",&a);
#define out(a) printf("%d",a);
#define INF 1000000 
#define M 1000000007
#define pi 3.14159265 
using namespace std; 
int main(){ 
   fast_io
   ll n;
   cin>>n;
   ll a[n];
   ll neg = 0;
   ll sum = 0;
   ll mini = MAX;
   vector<ll> v;
   for(ll i = 0;i<n;i++){
      cin>>a[i];
      if(a[i] < 0) neg++;
      sum += abs(a[i]);
      ll o = abs(a[i]);
      v.push_back(o);
   }
   if(neg % 2 == 0){
      cout<<sum<<endl;
   }
   else{
      sort(v.begin(),v.end());
      ll ans = 0;
      ans -= v[0];
      for(ll i = 1;i<v.size();i++){
          ans += v[i];
      }
      cout<<ans<<endl;
   }
   return 0; 
}  