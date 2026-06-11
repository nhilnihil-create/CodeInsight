#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<int> time(5);
    rep(i,5) cin >> time[i];
    vector<int> nexttime(5);
    rep(i,5) {
      nexttime[i] = 10*((time[i]+9)/10);
    }
    int ans = 1001001001;
    rep(i,5) {
      int sum = 0;
      rep(j,5) {
        if (i == j) sum += time[j];
        else sum += nexttime[j];
      }
      ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}