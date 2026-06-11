#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  pair<int, int> ba[m];
  for (int i=0; i<m; i++) {
    cin>>ba[i].second>>ba[i].first;
  }
  sort(ba, ba + m);
  int end = -1;
  int ans = 0;
  for (int i=0; i<m; i++) {
    if (ba[i].second >= end) {
      end = ba[i].first;
      ++ans;
    }
  }
  cout<<ans<<endl;
}