#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int k; cin >> k;
  set<string> st;
  for(int i = 0; i < (int)s.size(); i++){
    string t = "";
    for(int j = 0; j < k; j++){
      if(i + j >= s.size()) break;
      t += s[i+j];
      st.insert(t);
    }
  }
  string ans;
  int cnt = 0;
  for(auto p: st){
    cnt++;
    ans = p;
    if(cnt == k) break;
  }
  cout << ans << endl;
}