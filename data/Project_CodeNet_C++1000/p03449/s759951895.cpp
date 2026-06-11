#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a1(n);
  vector<int> a2(n);

  int sum1 = 0;
  int sum2 = 0;
  rep (i, n) cin >> a1[i];
  sum1 += a1[0];
  rep (i, n){
    cin >> a2[i];
    sum2 += a2[i];
  }

  int ans = sum1 + sum2;
  rep (i, n - 1){
    sum1 += a1[i+1];
    sum2 -= a2[i];
    int temp = sum1 + sum2;
    if (ans < temp) ans = temp;
  }
  cout << ans << endl;
  return 0;
}