#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for(int i=0; i<n; ++i)

//--------------------
#define MAX_N 200000

vector<int> V;
int a[MAX_N];

int main() {

  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  sort(a, a+n);

  int num = a[0];
  int cnt = 1;
  for(int i=1; i<n; ++i) {
    if(num==a[i]) {
      ++cnt;
    }else {
      V.push_back(cnt);
      cnt = 1;
      num = a[i];
    }
  }

  V.push_back(cnt);

  if(V.size()<=k) {
    cout << 0 << endl;
  }else {
    ll res = 0;
    sort(V.begin(), V.end());
    for(int i=0; i<V.size()-k; ++i) {
      res += V[i];
    }
    cout << res << endl;
  }

  return 0;
}
