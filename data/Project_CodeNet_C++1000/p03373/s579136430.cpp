#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {  
  return b != 0 ? gcd(b, a % b) : a;
}//MAX
int lcm(int a, int b) { 
   return a * b / gcd(a, b);
   }
//MIN

 main() {
int a,b,c,x,y;
cin >> a>> b >> c >> x >> y;
ll ans;
c*=2;
ans = max(x,y)*c;
for(ll i =0;i<=min(x,y);i++){
 ll che =a*(x-i)+b*(y-i)+c*i;
 ans = min(che,ans);
}
cout << ans << endl;
}
