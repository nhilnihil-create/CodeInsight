#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int k;
  cin >> s >> k;
  set<string> ans;
  for(int i=1; i<k+1; i++){
    for(int j=0; j<s.size()-(i-1); j++){
      ans.insert(s.substr(j,i));
    }
  }
  for(int i=0; i<k-1; i++){
    ans.erase(*begin(ans));
  }
  cout << *begin(ans) << endl;
}
