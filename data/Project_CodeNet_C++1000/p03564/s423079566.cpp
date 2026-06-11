#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  int K;

  cin >> N >> K;

  int S = 1;
  for (int i = 0 ; i < N ; i++) {
    if (S * 2 < S + K) {
      S *= 2;
    } else {
      S += K;
    }
  }

  cout << S << endl;

}

