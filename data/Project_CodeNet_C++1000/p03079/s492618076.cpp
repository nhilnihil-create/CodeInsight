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
cin >> a >> b >> c;
if(a==b&&b==c)cout <<"Yes"<<endl;
else cout <<"No"<<endl;
 }
