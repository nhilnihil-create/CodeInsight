#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0, cnt = 0;
  for(int i=1; i<n; ++i){
    cnt = 0;
    for(char c='a'; c<='z'; ++c){
      bool left = false, right = false;

      for(int j=0; j<i; ++j){
        if(s[j]==c) left = true;
      }

      for(int j=i; j<n; ++j){
        if(s[j]==c) right = true;
      }
      if(left && right) ++cnt;
    }
    if(ans<cnt) ans = cnt;
  }


  cout << ans << endl;

  return 0;
}