#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string x;
  cin >> x;
  
  int ans;
  for(int i=0; i < x.size()-2; i++){
    string str;
  	str += x[i];
    str += x[i+1];
    str += x[i+2];
    int num = stoi(str);
    if(i==0){
      ans = abs(753-num);
    }else{
      if(ans>abs(753-num)) ans = abs(753-num);
    }
  }
  
  cout << ans << endl;
}