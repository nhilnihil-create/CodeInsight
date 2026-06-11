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
  for (int q=0; q<t; q++){
      long long a, b, c, d;
      cin >> a >> b >> c >> d;
      if (a < b){
          cout << "No\n";
          continue;
      }
      long long x = max(0LL, b-d);
      if (x > c){
          cout << "No\n";
          continue;
      }
      long long plus = a%b; // 4
      long long gcdd = __gcd(b, d);
      long long maxx = ((b-1)-plus)/gcdd;
      maxx *= gcdd;
      maxx = (maxx+plus)%b;
      long long minn = b-plus;
      minn = minn/gcdd+(minn%gcdd != 0);
      minn = (minn*gcdd+plus)%b;
      //cout << "maxx: " << maxx << " minn: " << minn << " x: " << x << " c: " << c << endl;
      if (maxx < x || maxx > c || minn < x || minn > c){
          cout << "No\n";
      }else{
          cout << "Yes\n";
      }
  }
  return 0; 
}
