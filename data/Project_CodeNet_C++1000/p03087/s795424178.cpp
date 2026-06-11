#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
  string S;
  int N, Q,temp=0,l,r,f_ans;
  vi ans(100000);
  cin >> N >> Q >> S;
  rep(i,N-1)
  {
    if (S[i]=='A'&&S[i+1]=='C')
    {
      temp++;
    }
    ans[i] = temp;
  }

  rep(i,Q)
  {
    cin >> l >> r;
      if (S[l-1]=='A'&&S[l]=='C')
      {
        f_ans = ans[r - 2] - ans[l - 1] + 1;
      }
      else
      {
        f_ans = ans[r - 2] - ans[l - 1];
      }
    cout << f_ans << endl;
  }

  return 0;
}
