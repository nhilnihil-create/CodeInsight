#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; ++i) cin >> s[i];

  int m;
  cin >> m;
  vector<string> t(m);
  for(int i=0; i<m; ++i) cin >> t[i];

  string str, ans_str;
  int mx=0;

  for(int i=0; i<n; ++i){
    int cnt = 0;
    str = s[i];
    for(int j=0; j<n; ++j){
      if(str==s[j]) cnt++;
    }
    for(int k=0; k<m; ++k){
      if(str==t[k]) cnt--;
    }
    if(cnt>=mx){
      mx = cnt;
      ans_str = str;
    }
  }

  cout << mx << endl;
}