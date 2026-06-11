#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
  int n,i,ans=0;
  string s[3];
  cin >> n;
  for (i=0;i<3;i++) cin >> s[i];
  for (i=0;i<n;i++){
    if (s[0][i]==s[1][i] && s[1][i]==s[2][i]) continue;
    else if (s[0][i]==s[1][i] || s[1][i]==s[2][i] || s[2][i]==s[0][i]) ans++;
    else ans+=2;
  }
  cout << ans << endl;
  return 0;
}