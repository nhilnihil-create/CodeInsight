#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S;

int main(){
  cin >> S;

  int ans = 1000;
  rep(i, S.size()){
    string s = S.substr(i, 3);
    ans = min(ans, abs(753-stoi(s)));
  }
  cout << ans << endl;
}
