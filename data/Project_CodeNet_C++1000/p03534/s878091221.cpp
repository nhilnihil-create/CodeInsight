#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Ti = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string s;
  cin >> s;
  int n = s.size();
  int cnt[3] = {};
  rep(i, n) {
    cnt[s[i]-'a']++;
  }
  int a = abs(cnt[0]-cnt[1]);
  int b = abs(cnt[1]-cnt[2]);
  int c = abs(cnt[2]-cnt[0]);
  if(a <= 1 && b <= 1 && c <= 1) cout << "YES" << endl;
  else cout << "NO"<<endl;

  return 0;
}
