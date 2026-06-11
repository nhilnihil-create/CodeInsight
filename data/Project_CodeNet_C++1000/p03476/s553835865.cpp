#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// 素数判定
bool prime (int i) {
  bool can = true;
  for (int j=2; j<=sqrt(i); j++) {
    if (i%j==0) {
      can = false;
      break;
    }
  }
  return can;
}

int main() {
  int Q;
  cin >> Q;
  vector<int> l(Q), r(Q); // 素数テーブル
  for (int i=0; i<Q; i++) cin >> l[i] >> r[i];
  vector<int> memo(100001, 0); // memo[i]:=i(1<=i<=100000)以下の2017に似た数の個数
  for (int i=3; i<=100000; i++) {
    if (prime(i)&&prime((i+1)/2)) memo[i] = memo[i-1]+1;
    else memo[i] = memo[i-1];
  }
  for (int i=0; i<Q; i++) cout << memo[r[i]]-memo[l[i]-1] << endl;
  return 0;
}