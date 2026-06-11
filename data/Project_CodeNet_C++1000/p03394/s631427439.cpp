#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 釈然としない悔しさ定期
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n; cin >> n;
  if(n == 3) return(cout << "2 5 63" << endl, 0);
  vector<int> ans;
  int k = n;
  int a[] = {1, 3, 2, 8, 7, 9};
  int b[] = {5, 11};
  for(int i = 1; i <= 3e4; i += 12) {
    for(int j = 0; j < 6; j += 2) {
      if(k < 2) break;
      ans.emplace_back(i + a[j]);
      ans.emplace_back(i + a[j + 1]);
      k -= 2;
    }
    for(int j = 0; j < 2; j++) {
      if(k < 1) break;
      ans.emplace_back(i + b[j]);
      k--;
    }
    if(k == 0) break;
  }
  cout << ans[0];
  for(int i = 1; i < n; i++) cout << " " << ans[i];
  cout << endl;
}
