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
int a,b,c;
int ans =0;
cin >> a >> b >> c;
c--;
ans++;
int che = min(c,b);
while(che!=0){
   c--;
   b--;
   che--;
   ans++;
   ans++;
}
che = min(a,c);
while(che!=0){
   c--;
   a--;
   che--;
   ans++;
}
cout << ans+b << endl;
 }
