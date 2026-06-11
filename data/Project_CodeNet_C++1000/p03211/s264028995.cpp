#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string x;
  cin >> x;
  
  int ans;
  rep(i,x.size()-2){
    string str = x.substr(i,3);
    int num = stoi(str);
    num = abs(753-num);
    if(i==0){
      ans = num;
    }else{
      if(ans>num) ans = num;
    }
  }
  
  cout << ans << endl;
}