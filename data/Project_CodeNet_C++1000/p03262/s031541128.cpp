#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)

int gcd(int a, int b){
   if(a%b == 0){
   return(b);
   }
   else return(gcd(b, a%b));
}

int main() {
 ll n,x; cin >> n >> x;
 vector<ll> co(n);
 rep(i,n){
   ll xi; cin >> xi;
   co[i]=abs(xi-x);
 }
 ll m;
 for(int i=0;i<n-1;i++){
   m=gcd(co[i],co[i+1]);
   co[i+1]=m;
 }

 cout << co[n-1] << endl;

}
