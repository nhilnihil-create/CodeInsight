#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  bool ok = true;
  int l = s.size();
  for(int i = 0; i < l; i++){
    int k = s.at(i) - '0';
    if(i == a){
      if(k >= 0 && k <= 9) ok = false;
    }
    else{
      if(k < 0 || k > 9) ok = false;
    }
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}