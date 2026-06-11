#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s,t;
  cin >> s >> t;
  
  int n = s.size();
  int ans = 0;
  for(int i = 0; i < n; i++){
    int k = 0;
    for(int j = i; ; j++){
      if(ans == n){
        cout << "Yes" << endl;
        return 0;
      }
      if(t[k] == s[j]){
        ans++;
        k++;
      }else if(t[k] != s[j]){
        break;
      }
       if(j == n-1){
        j = -1;
      }
    }//for
    ans = 0;
  }
  
  cout << "No" << endl;
}