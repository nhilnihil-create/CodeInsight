#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.size() < 3){
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0,ac = 1;
  for(int i = 0;i < s.size()-2;i++){
    if(s[i] == 'A' && s[i+1] == 'A') ac++;
    else if(s.substr(i,3) == "ABC"){
      ans += ac;
      s[i+2] = 'A';
      i++;
    }
    else{
      ac = 1;
    }
  }
  cout << ans << endl;
}
