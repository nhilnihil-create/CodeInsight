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
using P = pair<ll,ll>;

int main(){

  ll N, M;
  cin >> N >> M;
  vector<P> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if(M <= 0) break;
    int num = min(M, p[i].second);
    ans += num * p[i].first;
    M -= num;
  }

  cout << ans << endl;


  return 0;
}