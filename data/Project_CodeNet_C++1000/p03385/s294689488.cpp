#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  vector<int> cnt(3);
  for(int i = 0; i < 3; i++){
    cnt.at(i) = s.at(i) - 'a';
  }
  sort(cnt.begin(), cnt.end());
  bool ok = true;
  for(int i = 0; i < 3; i++){
    if(cnt.at(i) != i) ok = false;
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}