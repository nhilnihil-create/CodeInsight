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
  int a[n];
  int b[n];
  int balance = 0;
  REP(i,n) cin >> a[i];
  REP(i,n) {
    int tmp = in();
    int diff = tmp - a[i];
    if(diff > 0) balance += diff/2;
    else if(diff < 0) balance += diff;
  }
  
  if(balance >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
/***** MAIN *****/
