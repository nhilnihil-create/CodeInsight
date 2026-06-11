#include<bits/stdc++.h>
using namespace std;
int lg(int a) {
  int k = 1;
  int kj = 10;
  while (a >= kj) {
    k ++;
    kj *= 10;
  }
  return k;
}
int main () {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>>P(M);
  vector<pair<int, int>>ans(M);
  for (int i = 0; i < M; i ++) {
    int p, x;
    cin >> p >> x;
    P[i] = make_tuple(p, x, i);
  }
  sort(P.begin(), P.end());
  int j = 0;
  for (int i = 1; i <= N; i ++) {
    int al = 1;
    while (j < M && get<0>(P[j]) == i) {
      int p, y, kj;
      tie(p, y, kj) = P[j];
      ans[kj] = make_pair(p, al);
      al ++;
      j ++;
    }
  }
  for (int i = 0; i < M; i ++) {
    int p, y;
    tie(p, y) = ans[i];
    int a = lg(p);
    int b = lg(y);
    for (int j = 0; j < 6 - a; j ++) cout << 0;
    cout << p;
    for (int j = 0; j < 6 - b; j ++) cout << 0;
    cout << y << endl;
  }
  //cout << lg(N) << endl;
  //cout << lg(M) << endl;
}

