// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  int N, x;
  int ans = 0;
  cin >> N >> x;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  sort(A.begin(),A.end());
  rep(i,N) {
    if(A[i] <= x){
      ans++;
      x -= A[i];
    }
  }

  if(ans == N && x > 0) ans--;
  cout << ans << endl;
  return 0;
}