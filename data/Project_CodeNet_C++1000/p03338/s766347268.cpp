#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> cnt(N-1, 0);
  for (int i = 1; i < N; i++) {
    string left = S.substr(0, i);
    string right = S.substr(i, N-1);
    for (char c = 'a'; c <= 'z'; c++) {
      if ((left.find(c) != string::npos) && (right.find(c) != string::npos)) {
        cnt[i-1]++;
      }
    }
  }
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  cout << cnt[0] << endl;
}