#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int pos = -1, neg = 0, poskeep, negkeep;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    if(a.at(i) > pos){
      pos = a.at(i);
      poskeep = i;
    }
    if(a.at(i) < neg){
      neg = a.at(i);
      negkeep = i;
    }
  }
  
  vector<pair<int, int>> ans;
  if(pos >= neg * (-1)){
    for(int i = 0; i < n; i++){
      if(a.at(i) < 0){
        ans.push_back(make_pair(poskeep + 1, i + 1));
        a.at(i) += pos;
      }
    }
    for(int i = 1; i < n; i++){
      if(a.at(i - 1) > a.at(i)){
        ans.push_back(make_pair(i, i + 1));
        a.at(i) += a.at(i - 1);
      }
    }
  }
  else{
    for(int i = 0; i < n; i++){
      if(a.at(i) > 0){
        ans.push_back(make_pair(negkeep + 1, i + 1));
        a.at(i) += neg;
      }
    }
    for(int i = n - 2; i >= 0; i--){
      if(a.at(i) > a.at(i + 1)){
        ans.push_back(make_pair(i + 2, i + 1));
        a.at(i) += a.at(i + 1);
      }
    }
  }
  
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++){
    cout << ans.at(i).first << " " << ans.at(i).second << '\n';
  }
}