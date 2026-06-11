#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int> d(n);
  for(int i=0; i<n; i++)
    cin >> d[i];

  sort(d.begin(), d.end());

  int ans = 0, idx = 0;
  while(idx < n){
    while(d[idx] == d[idx+1])  idx++;
    ans++;
    idx++;
  }
  cout << ans << endl;
  return 0;
}
