#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;
  cin >> s;
  int ans; 
  string op;
  vector<int> num(4);
  rep(i,4){
      num[i] = s[i]-'0';
  }
  rep(bit,1<<3){
    ans = num[0];
    rep(i,3){
      if(bit&(1<<i)){
        ans+=num[i+1];
        op[i]='+';
      }else{
        ans -= num[i+1];
        op[i]='-';
      }
    }
    if(ans == 7){
        break;
    }
  }
  cout<< num[0] << op[0] << num[1] << op[1] << num[2] << op[2] << num[3]  << "=7" << endl;
}
