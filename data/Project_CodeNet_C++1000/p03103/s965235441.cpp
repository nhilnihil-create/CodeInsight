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
#define lli long long int

using namespace std;
using P = pair<ll,ll>;

int main(){

  ll N, M;
  cin >> N >> M;
  ll ans = 0;

  vector<P> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());

  for (int i = 0; i < N; i++) {
    if(M < 0) break;

    if(M - p[i].second >= 0){
      ans += p[i].first * p[i].second;
    }else if (M - p[i].second < 0){
      ans += p[i].first * M;
    }
    M = M - p[i].second;

  }

  cout << ans << endl;

  return 0;
}