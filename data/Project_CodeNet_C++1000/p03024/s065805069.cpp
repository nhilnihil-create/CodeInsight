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
cin >> s;
int ans = 0;
for(int i=0;i<s.size();i++){
   if(s.at(i)=='x')ans++;
}
if(ans<8){
   cout<<"YES"<<endl;
}
else{
   cout<<"NO"<<endl;
}
 }
