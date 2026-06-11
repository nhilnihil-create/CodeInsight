#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string x;
  cin >> x;
  
  int ans;
  rep(i,x.size()-2){
    string str;
    str += x[i];
    str += x[i+1];
    str += x[i+2];
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