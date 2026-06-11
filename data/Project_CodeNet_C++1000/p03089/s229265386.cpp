#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

int n,W;
int main() {
  int n;
  cin >> n;
  vector<int> b;
  int ans[n] , kaisuu = 0;
  REP(i,n) {
    int ci;
    cin >>ci;
    b.pb(ci);
    if (b[i] >i+1) {
      cout << "-1";
      return 0;
    }
  }
  while (b.size() != 0) {
    for(int i = b.size() - 1;i>=0;i--) {
      if(b[i] == i + 1) {
        ans[kaisuu] = b[i];
        kaisuu++;
        b.erase(b.begin() + i);
        break;
      }
    }
  }
  REP(i,n) {
    cout <<ans[n-i-1] << endl;
  }
}