#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t;  cin >> s >> t;
  int table_len = (int)'z' - (int)'a' + 1;
  vector<int> stable(table_len, 0), ttable(table_len, 0);
  for(int i=0; i<s.size(); i++){
    stable[(int)s[i]-(int)'a']++;
    ttable[(int)t[i]-(int)'a']++;
  }
  sort(stable.begin(), stable.end());
  sort(ttable.begin(), ttable.end());
  string ans = "Yes";
  for(int i=0; i<table_len; i++)
    if(stable[i] != ttable[i])  ans = "No";

  cout << ans << endl;
  return 0;
}
