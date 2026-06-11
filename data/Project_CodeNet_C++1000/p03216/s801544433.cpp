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

int main(){
  prep();
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  long long csum[n] = {0};
  long long msum[n] = {0};
  for (int i=0; i<n; i++){
      if (s[i] == 'C'){
          csum[i]++;
      }else if (s[i] == 'M'){
          msum[i]++;
      }
  }
  for (int i=1; i<n; i++){
      csum[i] += csum[i-1];
      msum[i] += msum[i-1];
  }
  long long sums[n] = {0};
  for (int i=0; i<n; i++){
      if (s[i] == 'C'){
          sums[i] = msum[i];
      }
  }
  for (int i=1; i<n; i++){
      sums[i] += sums[i-1];
  }
  for (int i=0; i<q; i++){
      int k;
      cin >> k;
      long long res = 0;
      for (int j=0; j<n-2; j++){
          if (s[j] == 'D'){
              long long myval = sums[min(j+k-1, n-1)]-sums[j];
              long long cs = csum[min(j+k-1, n-1)];
              cs -= csum[j];
              if (j > 0){
                  myval += -msum[j-1]*cs;
              }
              res += myval;
          }
      }
      cout << res << '\n';
  }
  return 0; 
}