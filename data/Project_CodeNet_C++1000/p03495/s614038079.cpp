#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for(int i=0; i<n; ++i)

//--------------------
#define MAX_N 200000

vector<int> V(MAX_N+1);

int main() {

  int n, k, m;
  cin >> n >> k;
  rep(i, n) {
    cin >> m;
    ++V[m-1];
  }

  sort(V.begin(), V.end(), greater<int>());
  ll ans = 0;
  rep(i, k) {
    ans += V[i];
  }

  cout << n-ans << endl;
  
  return 0;
}
