#include <bits/stdc++.h>
using namespace std;
vector<string> vec;

void dfs(string S, int i){
  if(i >= S.size()) return;
  string tmp = S;
  if(tmp[i] == 'A') {
    tmp.erase(i, 1);
    vec.push_back(tmp);
    dfs(tmp, i);
  }
  dfs(S, i+1);
}

int main(void){
  string S;
  cin >> S;
  vec.push_back("AKIHABARA");
  dfs("AKIHABARA", 0);

  bool tf = true;
  for(int i=0; i<vec.size(); i++) {
    if(S == vec[i]) break;
    if(i == vec.size()-1) tf = false;
  }
  if(tf) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}