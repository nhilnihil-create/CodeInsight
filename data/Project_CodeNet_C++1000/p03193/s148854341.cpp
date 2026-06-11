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
int n,a,b,ans=0;
cin >> n >> a >> b;
for(int i=0;i<n;i++){
   int aa,bb;
   cin >> aa >> bb;
   if(aa>=a&&bb>=b)ans++;
}
cout << ans << endl;
 }
