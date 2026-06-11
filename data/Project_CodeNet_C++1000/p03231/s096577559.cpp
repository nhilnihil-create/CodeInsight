#include <bits/stdc++.h>
using namespace std;
//最大公約数
long long GCD(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(GCD(b, a%b));
   }
}
//最小公倍数
long long LCM(long long a, long long b)
{
   return a * b / GCD(a, b);
}
int main() {
  int N,M;
  cin >> N >> M;
  string S,T;
  cin >> S >> T;
  int gcd = GCD(N,M);
  int n = N/gcd;
  int m = M/gcd;
  for(int i=0; i<gcd; i++){
    if(S[n*i] != T[m*i]){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << LCM(N,M) << endl;
}
