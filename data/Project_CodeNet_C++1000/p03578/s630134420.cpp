#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M; 
  map<int, int> D, T;
  cin >> N;
  rep(i, N) {
    int d;
    cin >> d;
    if (D.count(d)) {
      D[d]++;
    }
    else {
      D[d] = 1;
    }
  }
  cin >> M;
  rep(i, M) {
    int t;
    cin >> t;
    if (T.count(t)) {
      T[t]++;
    }
    else {
      T[t] = 1;
    }
  }
  for (auto p : T) {
    int pnum = p.first;
    int pcont = p.second;
    if (!D.count(pnum) || D[pnum] < pcont) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}