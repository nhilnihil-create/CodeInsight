#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int s(int64 n) {
  int ret = 0;
  while(n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main() {
  vector< int64 > candidate;
  for(int i = 0; i <= 15; i++) {
    int64 base = 1;
    for(int j = 0; j < i; j++) base *= 10;
    for(int j = 1; j < 1000; j++) {
      candidate.push_back(base * j + (base - 1));
    }
  }
  sort(begin(candidate), end(candidate));
  candidate.erase(unique(begin(candidate), end(candidate)), end(candidate));
  int K;
  vector< int64 > ret;
  for(int i = 0; i < candidate.size(); i++) {
    bool f = true;
    for(int j = i + 1; j < candidate.size(); j++) {
      int64 n = candidate[i], m = candidate[j];
      if((__int128_t) n * s(m) > (__int128_t) m * s(n)) {
        f = false;
        break;
      }
    }
    if(f) ret.push_back(candidate[i]);
  }
  cin >> K;
  for(int i = 0; i < K; i++) {
    cout << ret[i] << endl;
  }
}
