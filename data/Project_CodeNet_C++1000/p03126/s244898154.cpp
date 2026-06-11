#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;

int main(){

  int N, M, K, A;
  cin >> N >> M;
  int ans = 0;

  vector<pair<int, int>> p(M);
  for (int i = 0; i < M; i++) {
    p[i] = make_pair(i, 0);
  }

  for (int i = 0; i < N; i++) {
    cin >> K;
    for (int j = 0; j < K; j++) {
      cin >> A;
      p[A-1].second += 1;
    }
  }

  for (int i = 0; i < M; i++) {
    if(p[i].second == N)ans++;
  }

  cout << ans << endl;

  return 0;
}