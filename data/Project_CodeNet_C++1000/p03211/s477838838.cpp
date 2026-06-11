#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 999, tmp, sa;
  for (int i = 0; i < s.size() - 2; i++){
    tmp = ((int)s.at(i) - 48) * 100 + ((int)s.at(i + 1) - 48) * 10 + ((int)s.at(i + 2) - 48);
    sa = abs(tmp - 753);
    ans = min(sa, ans);
  }
  cout << ans << endl;
}