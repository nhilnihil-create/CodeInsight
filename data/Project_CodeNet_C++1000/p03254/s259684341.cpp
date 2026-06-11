#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  int max = 0;
  rep(i, n){
    cin >> v[i];
    max += v[i];
  }

  sort(v.begin(), v.end());
  int ans = 0;
  int sum = 0;
  rep(i, n){
    if ((sum + v[i]) > x) break;
    ans = i + 1;
    sum += v[i];
  }

  if (n == ans && sum != x){
    ans -= 1;
  }

  cout << ans << endl;
  return 0;
}