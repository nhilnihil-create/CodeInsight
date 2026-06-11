#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  string l;
  cin >> n >> l;
  vector<int> s(n + 1, 0);
  vector<int> ans(n, 0);
  
  for (int i = 0; i < n; i++){
    if (l.at(i) == 'W'){
      s.at(i + 1) = s.at(i) + 1;
    }
    else{
      s.at(i + 1) = s.at(i);
    }
  }
  
  for (int i = 0; i < n; i++){
    ans.at(i) = s.at(i) + (n - (i + 1) - (s.at(n) - s.at(i + 1)));
  }
  
  sort(ans.begin(), ans.end());
  
  cout << ans.at(0) <<endl;
 
}