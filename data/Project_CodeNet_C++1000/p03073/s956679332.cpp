#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  if(s[0]=='0'){
    for(int i=0; i<n; ++i){
      if(i%2==0){
        if(s[i]!='0') cnt++;
      }
      else if(i%2==1){
        if(s[i]!='1') cnt++;
      }
    }
  }
  int cnt1 = 0;
  if(s[0]=='1'){
    for(int i=0; i<n; ++i){
      if(i%2==0){
        if(s[i]!='1') cnt1++;
      }
      else if(i%2==1){
        if(s[i]!='0') cnt1++;
      }
    }
  }


  cout << max(cnt, cnt1);
  return 0;
}