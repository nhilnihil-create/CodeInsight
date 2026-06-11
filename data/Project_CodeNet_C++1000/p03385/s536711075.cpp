#include <bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  map<char, int> mp;
  for(auto e : s) mp[e]++;
  bool f = true;
  for(auto e : mp){
    if(e.second != 1) f = false;
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}
