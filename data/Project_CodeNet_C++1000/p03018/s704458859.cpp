#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int l = s.size();
  long long ans = 0, cnt = 0;
  bool ok = false;
  for(int i = 0; i < l; i++){
    char now = s.at(i);
    if(ok){
      if(now == 'C') ans += cnt, ok = 0;
      else if(now == 'A') cnt = 1, ok = 0;
      else cnt = 0;
    }
    else{
      if(now == 'A') cnt++;
      else if(now == 'B') ok = true;
      else cnt = 0;
    }
  }
  
  cout << ans << endl;
}