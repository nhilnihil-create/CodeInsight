#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  string s[n];
  rep(i,n) cin >> s[i];
  
  for(int i = 1; i < n; i++){
    int sizel = s[i-1].size(); 
    rep(j,i){
      if(s[i][0] != s[i-1][sizel-1] || s[i] == s[j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  cout << "Yes" << endl;
}