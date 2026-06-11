#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> b(N);
  for(lint i = 0; i < N; i++) cin >> b[i];
  vector<lint> a;
  for (lint i = 0; i < N; i++) {
    for (lint j = b.size() - 1; j >= 0; j--) {
      if (j + 1 == b[j]) {
        a.push_back(j + 1);
        b.erase(b.begin() + j);
        break;
      }
    }
  }
  if(a.size() != N) cout << -1 << endl;
  else{
    for(lint i = N - 1; i >= 0; i--) cout << a[i] << " ";
    cout << endl;
  }
}