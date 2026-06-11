#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // i人目の参加者がt個をチョコレートを食べたとすると、
  // D<=ta[i]+1を満たす最大のtを求める

  vector<int> maisuu(n);
  for (int i = 0; i < n; i++) {
    maisuu[i] = (d - 1) / a[i] + 1;
    // cout << maisuu[i] << endl;
  }
  cout << x + accumulate(maisuu.begin(), maisuu.end(), 0) << endl;
}