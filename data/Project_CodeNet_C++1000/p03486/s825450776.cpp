#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  vector<char> sv, tv;
  for(int i=0; i<s.length(); i++){
    sv.push_back(s[i]);
  }
  for(int i=0; i<t.length(); i++){
    tv.push_back(t[i]);
  }
  sort(sv.begin(), sv.end());
  sort(tv.begin(), tv.end(), greater<int>());
  s = ""; t = "";
  for(int i=0; i<sv.size(); i++){
    s += sv[i];
  }
  for(int i=0; i<tv.size(); i++){
    t += tv[i];
  }
  if(s < t) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}