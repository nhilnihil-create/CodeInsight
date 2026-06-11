#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int k;
  cin >> s >> k;
  
  int l = s.size();
  set<string> sub;
  for(int i = 0; i < l; i++){
    for(int j = 1; j <= k; j++){
      string now = s.substr(i, j);
      sub.insert(now);
    }
  }
  
  vector<string> ans(0);
  for(auto now : sub){
    ans.push_back(now);
  }
  sort(ans.begin(), ans.end());
  
  cout << ans.at(k-1) << endl;
}