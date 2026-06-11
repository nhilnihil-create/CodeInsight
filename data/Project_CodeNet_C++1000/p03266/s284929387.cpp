#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> num(K, 0);
  // num[x] = K で割って余る数が1以上N以下に何個あるか
  for (int i = 1; i <= N; i++) num[i % K]++;
  long long ans = 0;
  rep(a, K) {
    int b = (K - a) % K;
    int c = (K - a) % K;
    if ((b + c) % K != 0) continue;
    ans += num[a] * num[b] * num[c];
  }
  cout << ans << endl;
}
