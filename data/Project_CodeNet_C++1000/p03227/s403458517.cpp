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
string s;
cin >>s;
if(s.size()==3){
    reverse(s.begin(),s.end());
    cout << s;
}
else{
    cout << s << endl;
}
 }
