#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]){
    cout << "Yes";
  }
  else if(s[3] == s[1] && s[1] == s[2]){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
  return 0;
}




