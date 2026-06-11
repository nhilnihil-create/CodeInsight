#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> strs(3);
  for(auto&i:strs)cin>>i;
  int ans = 0;
  for(int i=0;i<n;++i){
    set<char> s;
    for(int j=0;j<3;++j){
      s.emplace(strs[j][i]);
    }
    ans += s.size() - 1;
  }
  cout << ans << endl;
}
