#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

ll gcd(ll a,ll b){
  if (b) return gcd(b,a%b);
  return a;
}

int main(){
   int n,x;
   cin >> n >> x;
   vector<ll> v(n+1);
   rep(i,n) cin >> v[i];
   v[n] = x;
   sort(v.begin(),v.end());
   
   ll ans = v[1]- v[0];
   for (int i = 1; i < n;i++){
     ll tmp = v[i+1]-v[i];
     ans = gcd(ans,tmp);
   }
   cout << ans << endl;
  
  return 0; 
}

