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
using P = pair<int,int>;

int main(){

  int N, K, h;
  cin >> N >> K;
  int ans = 1e9;

  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> h;
    vec.at(i) = h;
  }
  sort(vec.begin(), vec.end());

  int diff = 0;
  for (int i = 0; i <= N-K; i++) {
    diff = vec.at(i+K-1) - vec.at(i);
    ans = min(ans, diff);
  }

  cout << ans << endl;

  return 0;
}