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
  int a;
  cin >> a;
  double sum = 0.00000;
  rep(i,a){
    double b;
    string c;
    cin >> b >> c;
    if(c=="BTC")b *= 380000.0;
    sum += b;
  }
cout << sum;
}
