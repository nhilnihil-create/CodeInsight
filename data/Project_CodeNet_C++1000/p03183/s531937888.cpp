#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> w(n), s(n), v(n);
  for(int i = 0; i < n; i++) cin >> w[i] >> s[i] >> v[i];
  vector<int> od(n);
  iota(od.begin(), od.end(), 0);
  sort(od.begin(), od.end(), [&](int a, int b){
    if(s[a] + w[a] == s[b] + w[b]) return v[a] > v[b];
    return s[a] + w[a] < s[b] + w[b];
  });
  const int l = 2 * 10100;
  vector<long long> f(l + 1, 0);
  for(int i = 0; i < n; i++){
    int id = od[i];
    for(int j = s[id]; j >= 0; j--){
      f[j + w[id]] = max(f[j + w[id]], f[j] + v[id]);
    }
  }
  long long ans = 0;
  for(int i = 0; i <= l; i++) ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
