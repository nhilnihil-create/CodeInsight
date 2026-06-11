#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

int main ()
{
  prep();
  int n;
  cin >> n;
  int a[n];
  int b[n];
  bool notequal = false;
  long long sum = 0;
  for (int i=0; i<n; i++){
      cin >> a[i];
      cin >> b[i];
      sum += a[i];
      if (a[i] != b[i]){
          notequal = true;
      }
  }
  if (!notequal){
      cout << 0;
      return 0;
  }
 
  int minnest = 1000000001;
  for (int i=0; i<n; i++){
      if (a[i] > b[i]){
          minnest = min(minnest, b[i]);
      }
  }
  cout << sum-minnest;
  return 0; 
}
