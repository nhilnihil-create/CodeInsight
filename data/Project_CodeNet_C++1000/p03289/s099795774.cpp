#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size();

  int cnt = 0;
  string ans = "AC";
  if(s[0]!='A'){
    ans = "WA";
    cout << ans << endl;
    return 0;
  }
  if(s[0]=='A'){
    for(int i=1; i<n; ++i){
      if(isupper(s[i])){
        if(i==1||i==n-1||s[i]!='C'){
          ans = "WA";
        }
        ++cnt;
      }
    }
  }
  if(cnt != 1){
    cout << "WA";
    return 0;
  }
  
  cout << ans;
  return 0;
}