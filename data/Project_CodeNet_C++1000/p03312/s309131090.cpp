#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, ans = (1LL << 62);
  cin >> N;
  vector<int64_t> A(N), S(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    S.at(i + 1) = A.at(i) + S.at(i);
  }
  for (int k = 3; k <= N - 1; k++) // 1-indexedでDが開始するindex
  {
    auto a = lower_bound(S.begin(), S.begin() + k, S.at(k - 1) / 2);
    int64_t ic = distance(S.begin(), a); // 前半の和の半分以上となる1-indexedのindex
    int64_t s1 = S.at(k - 1);
    int64_t ma1, ma2, maa, mia;
    ma1 = max(S.at(ic), s1 - S.at(ic));
    ma2 = max(S.at(ic - 1), s1 - S.at(ic - 1));
    maa = min(ma1, ma2);
    mia = s1 - maa;

    auto b = lower_bound(S.begin() + k + 1, S.end(), (S.at(N) - S.at(k - 1)) / 2 + S.at(k - 1));
    int64_t ie = distance(S.begin(), b); // 後半の和の半分以上となる1-indexedのindex
    int64_t s2 = S.at(N) - S.at(k - 1);
    int64_t mb1, mb2, mab, mib;
    mb1 = max(S.at(ie) - S.at(k - 1), s2 - (S.at(ie) - S.at(k - 1)));
    mb2 = max(S.at(ie - 1) - S.at(k - 1), s2 - (S.at(ie - 1) - S.at(k - 1)));
    mab = min(mb1, mb2);
    mib = s2 - mab;
    ans = min(ans, max(maa, mab) - min(mia, mib));
  }
  cout << ans << endl;
}