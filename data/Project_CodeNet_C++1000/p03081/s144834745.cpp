#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int N, Q;
string s;
vector<char> t(200010), d(200010);

bool vanish(int pos, bool left)
{
  bool flag = false;
  REP(i, Q)
  {
    if (t[i] == s[pos - 1])
    {
      if (d[i] == 'R')
        pos++;
      else
        pos--;
      if ((pos == 0 && left) || (pos == N + 1 && !left))
      {
        flag = true;
        break;
      }
    }
  }
  return flag;
}

int meguru(int ok, int ng, bool left)
{
  while (1 < abs(ok - ng))
  {
    int mid = (ok + ng) / 2;
    if (vanish(mid, left))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main()
{
  cin >> N >> Q;
  cin >> s;
  REP(i, Q)
  cin >> t[i] >> d[i];
  int left = meguru(0, N + 1, true);
  int right = meguru(N + 1, 0, false);
  cout << (right - 1) - left << endl;
  return 0;
}