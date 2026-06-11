#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

int digitSum(int n) {
  int res = 0;
  while(n > 0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

int main(void){
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (int i = 1; i <= N; i++){
    if (digitSum(i) >= A && digitSum(i) <= B) ans += i;
  }
  cout << ans << endl;
}
