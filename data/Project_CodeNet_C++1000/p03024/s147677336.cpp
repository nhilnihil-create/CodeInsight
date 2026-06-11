#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int cnt=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='x'){
      cnt++;
    }
  }
  if(cnt<=7){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}