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
int n,k;
cin >> n >> k;
int che = n-n/2;
if(che>=k)cout <<"YES"<<endl;
else cout <<"NO"<<endl;

}
