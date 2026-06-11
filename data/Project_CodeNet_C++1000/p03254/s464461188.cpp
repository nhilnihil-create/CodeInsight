#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int64_t N, x, S, ans;
  cin >> N >> x;
  S=0;
  ans=0;
  vector<int64_t> a(N);
  for (int64_t i=0; i<N; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  for (int j=0; j<N; j++) {
    S=S+a[j];
    if (S<=x) {
      ans=ans+1;
    }
  }
  if (S<x) {
    cout << ans-1 << endl;
  }
  else {
    cout << ans << endl;
  }
}