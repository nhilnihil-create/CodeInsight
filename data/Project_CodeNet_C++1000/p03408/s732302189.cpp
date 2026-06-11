#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  string s[n+1];
  rep(i,n) cin >> s[i];
  s[n] = "00";
 
  int m;
  cin >> m;
  string t[m];
  rep(i,m) cin >> t[i];
  
  sort(s,s+n);
  sort(t,t+m);
  
  int ans = 1, maxans = 0;;
  for(int i = 0; i < n; i++){
    if(s[i] == s[i+1]){
      ans++;
      continue;
    }
    for(int j = 0; j < m; j++){
      if(s[i] == t[j]){
        ans--;
      }
    }//for
    
    if(ans > maxans){
      maxans = ans;
    }
    ans = 1;
  }//for
  
  cout << maxans << endl;
}
