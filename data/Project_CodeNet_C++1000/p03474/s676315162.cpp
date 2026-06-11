#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b;
  string s;
  cin >> a >> b >> s;

  string t = "0123456789";

  bool flag = 1;
  for(int i = 0; i < s.size(); i++){
    if(i == a){
      if(s[i] != '-') {
        flag = 0;
        break;
      }
    }
    else{
      bool flag2 = 0;
      for(int j = 0; j < 10; j++){
        if(s[i] == t[j]) flag2 = 1;
      }
      if(!flag2){
        flag = 0;
        break;
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
