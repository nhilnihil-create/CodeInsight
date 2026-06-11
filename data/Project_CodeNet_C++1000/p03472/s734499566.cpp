#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;


int main() {
  int n, h;
  cin >> n >> h;
  vi a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int start = lower_bound(b.begin(), b.end(), a[n-1]) - b.begin();

  int ans = 0;
  for(int i=n-1;i>=start;i--){
    h -= b[i];
    ans++;
    if (h <= 0){
      cout << ans << endl;
      return 0;
    }
  }
  ans += h / a[n-1];
  if (h%a[n-1]) ans++;

  cout << ans << endl;
  return 0;
}