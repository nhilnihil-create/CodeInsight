#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  int ans = 0,cou = 0;
  rep(i,n){
    int j = i;
    while(s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T'){
      cou++;
      j++;
    }//while
    if(cou > ans){
      ans = cou;
    }
    cou = 0;
  }
  
  cout << ans << endl;
}
