#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  string s;
  cin >> n >> s;
  
  int alph1[27] = {0},alph2[26] = {0};
  int ans = 0, maxans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j <= i){
        alph1[s[j] - 'a'] = 1;
      }else{
        alph2[s[j] - 'a'] = 1;
      }//else
    }//for
    
    for(int i = 0; i < 27; i++){
      if(alph1[i] == 1 && alph2[i] == 1){
        ans++;
      }
    }
    if(ans > maxans){
      maxans = ans;
    }
    
    ans = 0;
    for(int i = 0; i < 27; i++){
      alph1[i] = 0;
      alph2[i] = 0;
    }
  }//for
  
  cout << maxans << endl;      
      
}