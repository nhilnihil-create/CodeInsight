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
vector<int>a(4);
for(int i=0;i<4;i++){
   cin >> a.at(i);
}
sort(a.begin(),a.end());
if(a.at(0)==1&&a.at(1)==4&&a.at(2)==7&&a.at(3)==9){
   cout << "YES"<<endl;
}
else{
   cout<<"NO"<<endl;
}
 }
