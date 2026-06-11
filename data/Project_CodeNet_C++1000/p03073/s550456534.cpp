#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  string s;
  cin >> s;
  int cnt = 0;
  rep(i,s.size()-1){
    if(s[i]==s[i+1]){
      cnt++;
      if(s[i+1] == '0') s[i+1] = '1';
      else s[i+1] = '0';
    }
  }
  cout << cnt << endl;
  return 0;
}