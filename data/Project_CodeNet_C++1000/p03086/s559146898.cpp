#include<bits/stdc++.h>
using namespace std;

string s;

int main(void){
  cin >> s;
  int ans = 0;
  for(int k = 1; k <= s.size(); k++){
      for(int i = 0; i < s.size(); i++){
      string si = s.substr(i, k);
      bool f = true;
      for(int j = 0; j < si.size(); j++){
        if(si[j] != 'A' && si[j] != 'C' && si[j] != 'G' && si[j] != 'T') f = false;
      }
      if(f) ans = max(ans, (int)si.size());
    }
  }
  cout << ans << endl;
  return 0;
}
