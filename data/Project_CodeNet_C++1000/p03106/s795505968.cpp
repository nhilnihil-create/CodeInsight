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
  int a,b,c;
  cin >> a >> b >> c;
  int GCD = __gcd(a,b),counter=0;
  for (int i = GCD; i > 0; i--){
    if(GCD%i==0){
      counter++;
      if(counter==c) cout << i;
    }
  }
} 
