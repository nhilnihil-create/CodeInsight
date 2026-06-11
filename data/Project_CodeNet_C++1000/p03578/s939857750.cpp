#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  for (int i=0; i<N; i++) cin >> D[i];
  int M;
  cin >> M;
  vector<int> T(M);
  for (int i=0; i<M; i++) cin >> T[i];
  // DとTそれぞれに登場する数字とその登場回数
  map<int, int> memoD, memoT;
  for (int i=0; i<N; i++) {
    if (memoD.count(D[i])) memoD[D[i]]++;
    else memoD[D[i]] = 1;
  }
  for (int i=0; i<M; i++) {
    if (memoD.count(T[i])) memoT[T[i]]++;
    else memoT[T[i]] = 1;
  }
  bool can = true;
  for (int i=0; i<M; i++) {
    if (memoT[T[i]]>memoD[T[i]]) {
      can = false;
      break;
    }
  }
  if (can) cout << "YES" << endl;
  else cout << "NO" << endl;
}