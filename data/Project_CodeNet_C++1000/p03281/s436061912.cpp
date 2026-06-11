#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  vi ans(201,0);
  ans.at(105) = 1;
  ans.at(165) = 1;
  ans.at(195) = 1;
  ans.at(135) = 1;
  ans.at(189) = 1;
  int a;
  cin >> a;
  a++;
  int sum = 0;
  for(int i = 0;i<a;i++){
    sum += ans.at(i);
  }
  cout << sum;
}