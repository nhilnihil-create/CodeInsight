#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  vector<int> cntOdd(110000);
  for (int i = 0; i < N; i += 2) {
    cntOdd.at(A.at(i))++;
  }

  vector<int> cntEven(110000);
  for (int i = 1; i < N; i += 2) {
    cntEven.at(A.at(i))++;
  }

  int maxOdd = -1;
  int index;
  for (int i = 0; i < cntOdd.size(); i++) {
    maxOdd = max(maxOdd, cntOdd.at(i));
    if (maxOdd == cntOdd.at(i)) index = i;
  }

  int maxEven = -1;
  for (int i = 0; i < cntEven.size(); i++) {
    if (index != i) maxEven = max(maxEven, cntEven.at(i));
  }

  int ans1 = (N / 2 - maxOdd) + (N / 2 - maxEven);

  maxEven = -1;
  for (int i = 0; i < cntEven.size(); i++) {
    maxEven = max(maxEven, cntEven.at(i));
    if (maxEven == cntEven.at(i)) index = i;
  }

  maxOdd = -1;
  for (int i = 0; i < cntOdd.size(); i++) {
    if (index != i) maxOdd = max(maxOdd, cntOdd.at(i));
  }

  int ans2 = (N / 2 - maxOdd) + (N / 2 - maxEven);

  cout << min(ans1, ans2) << endl;
}
