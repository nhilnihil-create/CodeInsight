#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,sum=0,bob=0;
  cin >> a;
  vi ans(a);
  rep(i,a){
    cin >> ans.at(i);
    sum += ans.at(i);
  }
  sort(ALL(ans));
  int i = 1;
  while(i<a){
    bob += ans.at(i);
    i += 2;
  }
  cout << abs(sum-bob*2);
}
