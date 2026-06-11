#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string ans="NO", chk="keyence", s;
    cin >> s;
    if(s!=chk){
    int n = s.size();
      for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
          string tmp = "";
          for(int k=0; k<n; k++){
            if(i<=k && k<=j) continue;
            else tmp.push_back(s[k]);
          }
          if(tmp==chk) ans = "YES";
        }
      }
    }else ans = "YES";
    cout << ans << endl;
}
