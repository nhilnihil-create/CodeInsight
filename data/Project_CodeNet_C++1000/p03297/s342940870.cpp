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
  int t;
  cin >> t;
  for (int z=0; z<t; z++){
      long long a, b, c, d;
      cin >> a >> b >> c >> d;
      if (a < b || b > d){
          cout << "No\n";
          continue;
      }
      if (c >= b-1){
          cout << "Yes\n";
          continue;
      }
      long long g = __gcd(b, d);
      long long l = (c+1)%g;
      long long r = (b-1)%g;
      if (b-c-1 >= g){
          cout << "No\n";
          continue;
      }
      long long amod = a%g;
      if (l <= amod && r >= amod || l >= amod && r <= amod){
          cout << "No\n";
          continue;
      }
      //cout << l << " " << r << endl;
      cout << "Yes\n";
  }
  return 0; 
}
