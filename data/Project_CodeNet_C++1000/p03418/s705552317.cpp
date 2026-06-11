#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main() {
 ll n,k; cin >> n >> k;
 if(k==0){
   cout << n*n << endl;
   return 0;
 }

 ll cnt=0;
 for(ll i=k+1;i<=n;i++){
   ll p=n/i; ll q=n%i;
   cnt+=p*(i-k);
   cnt+=max(0LL,q-k+1);
 }
 cout << cnt << endl;


}
