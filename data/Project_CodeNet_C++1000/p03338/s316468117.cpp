#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  int ans = 0;
  for(int i = 1; i < n; i++){
    int cnt = 0;
    string front = s.substr(0, i);
    string back = s.substr(i, n-i);
    set<char> k;
    for(auto n : front) k.insert(n);
    for(auto n : back){
      if(k.count(n)){
        cnt++;
        k.erase(n);
      }
    }
    ans = max(ans, cnt);
  }
  
  cout << ans << endl;
}