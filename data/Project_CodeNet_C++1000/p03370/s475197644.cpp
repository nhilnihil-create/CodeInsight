#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  int a,b;
  cin >> a >> b;
  int c,MIN = 1000000;
  rep(i,a){
    cin >> c;
    b-=c;
    MIN = min(MIN,c);
  }
  cout << a + b/MIN;
}