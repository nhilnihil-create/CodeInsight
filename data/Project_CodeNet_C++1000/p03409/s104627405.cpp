#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<pair<int, int>> r(n), b(n);
  for(int i = 0; i < n; i++) cin >> r.at(i).first >> r.at(i).second;
  for(int i = 0; i < n; i++) cin >> b.at(i).first >> b.at(i).second;
  
  vector<bool> r_used(n, false);
  
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    int keep = -1;
    for(int j = 0; j < n; j++){
      if(r.at(j).first < b.at(i).first && r.at(j).second < b.at(i).second && r_used.at(j) == false){
        if(keep == -1){
          keep = j;
          continue;
        }
        else if(r.at(j).second > r.at(keep).second){
          keep = j;
        }
      }
    }
    if(keep != -1){
      ans++;
      r_used.at(keep) = true;
    }
  }
  
  cout << ans << '\n';
}