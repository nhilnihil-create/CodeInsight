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

  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; i++) {
    AB[i] = make_pair(A[i], B[i]);
  }
  sort(AB.begin(), AB.end());

  ll ans = 0;

  for (int i = 0; i < N; i++) {
    int buy = min(M, AB[i].second);
    ans += AB[i].first * (ll)buy;
    M -= buy;
  }
  cout << ans << endl;

  return 0;
}