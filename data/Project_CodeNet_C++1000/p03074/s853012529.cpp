#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int N, K;
  string S;
  cin >> N >> K >> S;
  int left = 0, right = 0;
  int count = 0;
  int max = 0;
  int zeroCount = 0;
  while (right < N) {
    if (zeroCount == K) {
      while (S[left] == '1') {
        count--;
        left++;
      }
      if (S[left] == '0') {
        while (S[left] == '0') {
          count--;
          left++;
        }
      }
      zeroCount--;
    }
    if (S[right] == '0') {
      while (S[right] == '0') {
        count++;
        right++;
      }
      zeroCount++;
    }
    while (S[right] == '1') {
      count++;
      right++;
    }    if (count > max) {
      max = count;
    }
  }
  cout << max << endl;
}