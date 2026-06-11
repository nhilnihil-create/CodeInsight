#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, m;  cin >> n >> m;
  vector<pair<long, long>> cb;
  for(int i=0; i<n; i++){
    long a;  cin >> a;
    cb.push_back({a, 1});
  }
  for(int i=0; i<m; i++){
    int b, c;  cin >> b >> c;
    cb.push_back({c, b});
  }
  sort(cb.rbegin(), cb.rend());

  long num = 0, idx = 0, ans = 0;
  while(num < n){
    ans += cb[idx].first * min(cb[idx].second, n-num);
    num += cb[idx].second;
    idx++;
  }

  cout << ans << endl;

  return 0;
}