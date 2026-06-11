#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, n, r) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
int in() {int x; cin>>x; return x;}
string stin() {string s; cin>>s; return s;}
/***** MAIN *****/
signed main() {
  int n = in();
  int m = in();
  if(n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if(n == 1 || m == 1) {
    int ans = max(0LL, n*m-2);
    cout << ans << endl;
    return 0;
  }
  int h = max(0LL, n-2);
  int w = max(0LL, m-2);
  cout << h*w << endl;
  return 0;
}
/***** MAIN *****/
