#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
void dfs(string s){
  int n = s.size();
//  cout << n << ", " << s << endl;
  for(int i = 0; i < n; i++){
    string tmp = s;
    if(s[i] == 'A'){
      tmp = tmp.erase(i, 1);
//      cout << tmp << endl;
      vec.push_back(tmp);
      dfs(tmp);
    }
  }
  return ;
}

int main(void){
  string S;
  cin >> S;
  
  vec.push_back("AKIHABARA");
  dfs("AKIHABARA");
//  string s = "AKIHABARA";
//  cout << s << endl;
//  cout << s.erase(4, 1) << endl;
  bool tf = false;
  for(int i = 0; i < vec.size(); i++){
    if(S == vec[i]){
      tf = true;
      break;
    }
  }
  if(tf) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;  
}
