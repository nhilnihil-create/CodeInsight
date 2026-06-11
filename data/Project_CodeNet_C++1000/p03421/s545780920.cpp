#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  LL N, A, B;
  cin >> N >> A >> B;

  if (N < A + B - 1 || N > A * B) {
    cout << -1 << endl;
    return 0;
  }

  bool maked = false;
  for (int i = 1; i <= B; i++) {
    int remain = N - A * i;
    if (remain < 0) continue;
    int lengthA;
    vector<int> lengths;
    if (i < B) {
      lengthA = remain / (B - i);
      if (lengthA == 0) continue;
      if (remain > (B - i) * A) continue;
      for (int j = 0; j < B - i; j++) lengths.push_back(lengthA);
      for (int j = 0; j < remain % (B - i); j++) lengths[j]++;
      if (remain % (B - i) != 0) lengthA++;
    }
    if (i == B) {
      lengthA = 0;
    }
    vector<LL> output;
    LL offset = N - i * A;
    for (int j = 0; j < A; j++) {
      for (int k = 0; k < i; k++) {
        output.push_back(offset + j * i + i - k);
        //        cout << offset + j * i + i - k << endl;
      }
    }

    for (int j = 0; j < B - i; j++) {
      offset -= lengths[j];
      for (int k = 0; k < lengths[j]; k++) {
        int cand = offset + k + 1;
        if (cand <= 0) continue;
        // cout << cand << endl;
        output.push_back(cand);
      }
    }
    for (int i = 0; i < output.size(); i++) {
      cout << output[i];
      if (i == output.size() - 1)
        cout << endl;
      else
        cout << " ";
    }
    return 0;
  }

  if (!maked) {
    cout << -1 << endl;
  }

  return 0;
}