#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int tmp;
  int ans = 760;
  for (int i = 0; i < (n-2); ++i){
    tmp = (s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    ans = min(ans, abs(tmp-753));
  }
  cout << ans << endl;
}