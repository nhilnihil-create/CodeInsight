#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int a,b;
  string s;
  cin >> a >> b >> s;
  rep(i,0,s.size()){
    if(i != a && (s[i]-'0' > 9 || s[i]-'0' < 0)){
      cout << "No" << endl;
      return 0;
    }
    if(i == a && s[i] != '-'){
      cout << "No" << endl;
      return 0;
    }
  }cout << "Yes" << endl;
}