#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

//#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  ll N, t;
  cin >> N;
  vector<ll> a(N);
  rep(i, N){
    cin >> t;
    a[i] = t - i - 1;
  }
  sort(a.begin(), a.end());
  // 中央値を求める
  ll mid;
  if (N % 2 == 0) mid = (a[N/2]+a[N/2-1])/2;
  else mid = a[N/2];

  // 合計を求める
  ll ans = 0;
  rep(i, N){
    ans += abs(a[i] - mid);
  }
  cout << ans << endl;

}
