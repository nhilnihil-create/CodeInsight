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
  int a,b,sum=0,MAX=0;
  cin >> a;
  rep(i,a){
    cin >> b;
    MAX = max(MAX,b);
    sum += b;
  }
  cout << sum - MAX/2;
}