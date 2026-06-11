#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i=0; i<N; i++) cin >> s[i];
  int AB_num = 0, c1 = 0, c2 = 0, c3 = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<s[i].size()-1; j++) {
      if (s[i][j]=='A'&&s[i][j+1]=='B') AB_num++;
    }
    if (s[i][0]=='B'&&s[i][s[i].size()-1]=='A') c1++;
    else if (s[i][0]=='B') c2++;
    else if (s[i][s[i].size()-1]=='A') c3++;
  }
  int ans = AB_num;
  if (c1==0) ans += min(c2, c3);
  else if (c2+c3>0) ans += c1+min(c2, c3);
  else if (c2+c3==0) ans += c1-1;
  cout << ans << endl;
}