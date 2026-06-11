#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++){
    mp[a[i]]++;
  }
  int ans = 0;
  for (auto P : mp){
    if (P.second >= P.first){
      ans += P.second - P.first;
    } else {
      ans += P.second;
    }
  }
  cout << ans << endl;
}