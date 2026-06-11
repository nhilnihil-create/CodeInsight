#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
  string s;
  rep(i, 4) cin >> s[i];
  int ans;
  vector<char> op(3);
  rep(bit, (1 << 3))
  {
    bitset<3> tmp(bit);
    ans = s[0] - '0';
    rep(i, 3)
    {
      if (tmp.test(i))
      {
        ans += s[i + 1] - '0';
        op[i] = '+';
      }
      else
      {
        ans -= s[i + 1] - '0';
        op[i] = '-';
      }
    }
    if(ans == 7){
      string shiki;
      rep(t,3){
        shiki = shiki + s[t] + op[t];
      }
      shiki = shiki + s[3] + "=7";
      cout << shiki;
      break;
    }
  }
}
