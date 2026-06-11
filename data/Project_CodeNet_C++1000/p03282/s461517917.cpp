#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  ll k;
  cin >> s >> k;

  int cnt = 0;
  int n = s.size();
  for(int i=0; i<n; ++i) if(s[i]=='1') cnt++;
  if(cnt==n){
    cout << 1 << endl;
    return 0;
  }

  if(s[0]=='1' && k>=cnt){
    for(int i=0; i<n; ++i){
      if(s[i]=='1') continue;
      else{
        cout << s[i] << endl;
        return 0;
      }
    }
  }
  else cout << s[0] << endl;

}