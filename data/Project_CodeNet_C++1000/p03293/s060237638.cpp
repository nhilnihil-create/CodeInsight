#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size();
  bool flag = false;

  for(int i=0; i<n; ++i){
    if(s==t){
      flag = true;
      break;
    }
    s = s.back() + s.substr(0, n-1);
  }

  if(flag) cout << "Yes";
  else cout << "No";
}