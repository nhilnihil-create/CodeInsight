#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  int res = 0;
  for(int i = 0; i < 2; ++i){
    if(a > b){
      res += a;
      --a;
    }else{
      res += b;
      --b;
    }
  }
  
  cout << res << endl;
}