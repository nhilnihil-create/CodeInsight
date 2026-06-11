#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  string s;
  cin >> s;
  rep(i, 7){
    string s1 = "";
    int len = s.size();
    rep(j, s.size()){
      if(j < i || j >= i + (len - 7))
        s1 += s.at(j);
    }
    if(s1 == "keyence"){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  
}