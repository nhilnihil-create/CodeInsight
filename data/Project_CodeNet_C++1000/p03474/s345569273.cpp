#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  
  bool flag = true;
  for(int i = 0; i < a; i++){
    if(!isdigit(s[i])) flag = false;
  }
  if(s[a] != '-') flag = false;
  for(int i = a + 1; i < a + b + 1; i++){
    if(!isdigit(s[i])) flag = false;
  }
  
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}