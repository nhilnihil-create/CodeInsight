#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

// int ctoi(const char c){
//   if('0' <= c && c <= '9') return (c-'0');
//   return -1;
// }

// int gcd(int a, int b){
//   int ma = max(a,b);
//   int mi = min(a,b);
//   if(mi == 0) return ma;

//   return gcd(mi, ma%mi);
// }

int main(){
  int X, Y;
  cin >> X >> Y;
  cout << X + Y / 2 << endl;
  return 0;
}