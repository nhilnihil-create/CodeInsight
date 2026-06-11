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
  bool flag1 = true;
  while(flag1){
    flag1 = false;
    for(int i=0; i<n; ++i){
      if(s[i]=='1' && s[i+1]=='0'){
        cnt += 2;
        s.erase(i,2);
        flag1 = true;
      }

      if(s[i]=='0' && s[i+1]=='1'){
        cnt += 2;
        s.erase(i,2);
        flag1 = true;
      }
    }
      n = s.size();
  }
  cout << cnt << endl;
}