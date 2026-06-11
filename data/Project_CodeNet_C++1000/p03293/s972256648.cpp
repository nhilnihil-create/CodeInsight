#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  
  int n = s.size();
  
  int ans = 0;
  for (int i=0 ; i<n ; i++){
    if (s == t){
      ans = 1;
      break;
    }
    char push = s.at(0);
    s.erase(s.begin() + 0);
    s.push_back(push);
  }
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}