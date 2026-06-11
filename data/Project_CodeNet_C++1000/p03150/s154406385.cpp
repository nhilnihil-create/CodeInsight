#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s;
  cin >> s;
  string u="keyence",ans="NO";
  int l=s.size();
  for(int i=0;i<l;i++){
    for(int j=0;j<=l-i-1;j++){
      string cp=s;
      cp=cp.erase(i,j);
      if(u==cp){
        ans="YES";
      }
    }
  }
  cout << ans;
}