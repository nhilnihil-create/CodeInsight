#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  double hig = 0.006, a,b,c,tmp,Abs;
  int ans = 1;
  cin >> a >> b >> c >> tmp;
  Abs = abs(c - b + tmp*hig);
  rep(i,a-1){
    cin >> tmp;
    if(Abs>abs(c - b + tmp*hig)){
      Abs = abs(c - b + tmp*hig);
      ans = i + 2;
    }
  }
  cout << ans;
}