#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,j,ans;
  string s[10005];
  
  cin >> n;
  for (i=0;i<n;i++) cin >> s[i];
  
  ans=0;
  for (i=0;i<n;i++) for (j=0;j<s[i].size()-1;j++){
    if (s[i][j]=='A' && s[i][j+1]=='B') ans++;
  }
  
  int r,z,u;
  r=z=u=0;
  for (i=0;i<n;i++){
    if (s[i][0]=='B' && s[i][s[i].size()-1]=='A'){
      r++;
    }else if (s[i][0]=='B'){
      z++;
    }else if (s[i][s[i].size()-1]=='A'){
      u++;
    }
  }
  
  if (r>0){
    ans+=r-1;
    
    if (z>0){
      ans++;
      z--;
    }
    if (u>0){
      ans++;
      u--;
    }
  }
  
  ans+=min(z,u);
  
  cout << ans << endl;
  
  return 0;
}