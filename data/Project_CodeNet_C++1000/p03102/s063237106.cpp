#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m,c,ans = 0;
  cin >> n >> m >> c;
  vector<int> b(m);
  REP(i,m) cin >> b[i];
  REP(i,n){
	vector<int> a(m);
    REP(i,m) cin >> a[i];
    int sum = 0;
    REP(i,m){
      sum += a[i] * b[i];
    }
    if(sum > -(c)) ans++;
  }
      
  cout << ans << endl;
}
