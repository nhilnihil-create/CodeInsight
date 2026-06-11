#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  vector<int> dd(13);
  for(int i=0;i<n;i++) {
    cin >> d[i];
    dd[d[i]]++;
  }
  bool yes = true;
  for(int i=0;i<dd.size();i++) {
    if(i == 0 && dd[i] > 0) yes = false;
    if(i == 12 && dd[i] > 1) yes = false;
    if(i != 0 && i != 12 &&  dd[i] > 2) yes = false;
  }
  if(!yes) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  for(int i=0;i<pow(2, 11);i++) {
    bitset<11> b(i);
    vector<int> around(24);
    for(int j=0;j<13;j++) {
      if(j == 0) around[0] = 1;
      else if(j == 12) {
        if(dd[j]) around[12] = 1;
      }
      else if(dd[j] == 2) {
        around[j] = 1;
        around[24-j] = 1;
      }
      else if(dd[j] == 1) {
        if(b.test(j-1)) around[j] = 1;
        else around[24-j] = 1;
      }
    }
    int prev = 0;
    int tmp = 30;
    for(int j=0;j<24;j++) {
      if(j == 0) continue;
      if(around[j]) {
        chmin(tmp, j - prev);
        prev = j;
      }
    }
    chmin(tmp, 24-prev);
    chmax(ans, tmp);
  }
  cout << ans << endl;
}
