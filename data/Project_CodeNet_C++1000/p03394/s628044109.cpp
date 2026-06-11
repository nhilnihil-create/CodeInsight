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
  int sum = 0;
  vector<int> these;
  bool have[30001] = {false};
  for (int i=1; i<=30000 && these.size() < n-1; i++){
      if (i%2 == 0){
          sum += i;
          these.push_back(i);
          have[i] = true;
      }else if (i%3 == 0){
          sum += i;
          these.push_back(i);
          have[i] = true;
      }
      
  }
  int must2 = 0;
  int must3 = 0;
  if (sum%2 == 1){
      must2 = 1;
  }
  if (sum%3 == 1){
      must3 = 2;
  }else if (sum%3 == 2){
      must3 = 1;
  }
  int goodnum = 0;
  for (int i=1; i <=30000; i++){
      if (!have[i] && i%2 == must2 && i%3 == must3 && __gcd(i, sum) != 1){
          goodnum = i;
          break;
      }
  }
  
  for (int i : these){
      cout << i << " ";
  }
  cout << goodnum;
  return 0; 
}
