#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
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
/***** MAIN *****/
string s;
bool HaveCharBefore(int tail, char c) {
  --tail;
  for(int i = tail; i >= 0; --i) {
    if(s[i]==c) return true;
  }
  return false;
}

signed main() {
  cin >> s;
  map<char, bool> have_seen;
  if(s.length() == 26) {
    char tailChar = s[25];
    int ascTailIndex = 0;
    bool impossible = true;
    for(int i = 25; i > 0; --i) {
      if(s[i-1] < s[i]) {
        ascTailIndex = i-1;
        impossible = false;
        break;
      }
    }
    if(impossible) {
      cout << -1 << endl;
      return 0;
    }
    char smallest_char = 'z';
    for(int i = ascTailIndex+1; i < 26; ++i) {
      if(s[i] > s[ascTailIndex]) {
        if(smallest_char > s[i]) smallest_char = s[i];
      }
    }
    // char next_char = s[ascTailIndex] + 1;
    s = s.substr(0,ascTailIndex);
    cout << s + smallest_char << endl;
    return 0;
  }
  REP(i,s.length()) {
    have_seen[s[i]] = true;
  }
  for(char c = 'a'; c <= 'z'; ++c) {
    if(!have_seen[c]) {
      cout << s + c << endl;
      return 0;
    }
  }
  return 0;
}
/***** MAIN *****/
