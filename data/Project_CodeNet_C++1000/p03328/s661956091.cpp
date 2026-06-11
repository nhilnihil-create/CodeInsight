#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int high[1001];
  rep(i,1000){
    high[i] = high[i-1] + i;
  }
  int a,b;
  cin >> a >> b;
  cout << high[b-a] - b;
}