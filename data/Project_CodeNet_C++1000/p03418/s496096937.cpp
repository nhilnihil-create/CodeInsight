#include <bits/stdc++.h>
using namespace std;

int N, K;

long long solver() {
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    int k = K;
    long long tmp = i - K;
    if (tmp < 0) {
      tmp = 0;
    }
    if(k > 0){
      k--;
    }
    long long tmp2 = (N % i - k);
    if (tmp2 < 0 || (N % i == 0)) {
      tmp2 = 0;
    }
    ans += N / i * tmp + tmp2;
  }
  return ans;
}

int solver2() {
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (j % i >= K) {
        cout << i << " " << j << endl;
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N >> K;
  cout << solver() << endl;
  //cout << solver2() <<endl;
}
