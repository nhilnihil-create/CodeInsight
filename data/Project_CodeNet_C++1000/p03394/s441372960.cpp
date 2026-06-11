#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, cnte = 0, cnto = 0;
  cin >> N;
  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  if (N == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  }
  if (N == 5) {
    cout << "2 4 6 3 9" << endl;
    return 0;
  }

  vector<int> ans;
  set<int> se, so;
  for (int n = 2; cnte + cnto < N; n++) {
    if (n % 2 == 0) {
      ans.push_back(n);
      se.insert(n);
      cnte++;
    }
    if (n % 2 == 1 && n % 3 == 0) {
      ans.push_back(n);
      so.insert(n);
      cnto++;
    }
  }

  if (cnto % 2 == 1) {
    for (int i = N - 1; i >= 0; i--) {
      if (ans[i] % 2 == 1) {
        int tmp = ans[i] + 1;
        while (se.find(tmp) != se.end()) tmp += 2;
        ans[i] = tmp;
        se.insert(tmp);
        cnte += tmp / 2;
        break;
      }
    }
  }

  if (cnte % 3 == 1) {
    for (int i = N - 1; i >= 0; i--) {
      if (ans[i] % 2 == 0) {
        int tmp = ans[i] + 4;
        while (se.find(tmp) != se.end()) tmp += 6;
        ans[i] = tmp;
        break;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}