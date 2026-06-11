#include <bits/stdc++.h>
using namespace std;
int main(){
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());
  int ls = s.size();
  int lt = t.size();
  bool ok = ls < lt;
  if(lt > ls) t.erase(ls);
  for(int i=0; i<ls; ++i){
    if(s[i] < t[i]){
      cout << "Yes" << endl;
      return 0;
    }else if(s[i] > t[i]){
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}