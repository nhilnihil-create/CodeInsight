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
  int a[5],Min=10,ans=0;
  rep(i,5){
    cin >> a[i];
    if(a[i]%10==0)ans+=a[i];
    else {
      ans += (a[i]/10 + 1) *10;
      Min = min(Min,a[i]%10);
    }
  }
  cout << ans + Min -10;
}