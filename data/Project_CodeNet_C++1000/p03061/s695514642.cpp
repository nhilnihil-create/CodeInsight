#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> left(N+1, 0), right(N+1, 0);

  for(int i = 0; i < N; i++)      left[i+1] = gcd(A[i], left[i]);
  for(int i = N - 1; i >= 0; i--) right[i]  = gcd(A[i], right[i+1]);

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(gcd(left[i],right[i+1]), ans);
  }

  cout << ans << endl;

  return 0;
}
