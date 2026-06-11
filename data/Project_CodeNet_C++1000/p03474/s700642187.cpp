#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  if(n!=a+b+1){
    cout << "No" << endl;
    return 0;
  }
  if(s[a]!='-'){
    cout << "No" << endl;
    return 0;
  }
  int cnt =0;
  for(int i=0; i<n; ++i){
    if(s[i]=='-') cnt++;
    if(cnt>1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}