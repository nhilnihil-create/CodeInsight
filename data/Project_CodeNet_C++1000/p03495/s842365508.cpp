#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];
  vector<int> num(n);
  rep(i, n) num[a[i]-1]++;
  sort(num.begin(), num.end(), greater<int>());
  int cnt = 0;
  for(int i = k; i < n; i++){
    if(num[i]) cnt += num[i];
    else break;
  }
  cout << cnt << endl;
}
 