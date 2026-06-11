#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string YES = "Yes";
const string NO = "No";

int main()
{
  ll N;
  scanf("%lld",&N);
  string s;
  cin >> s;

  int red = 0;
  int blue = 0;
  for (auto c:s) {
    if (c=='R') red++;
    else blue++;
  }
  if (red>blue) cout << YES << endl;
  else cout << NO << endl;

  return 0;
}
