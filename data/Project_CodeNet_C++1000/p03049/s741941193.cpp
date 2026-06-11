#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long

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
int CountAB(string s) {
  int counter = 0;
  auto pos = s.find("AB");
  while(pos != string::npos) {
    ++counter;
    pos = s.find("AB",pos+2);
  }
  return counter;
}
/***** MAIN *****/
signed main() {
  int n;
  cin >> n;
  string ss[n];
  REP(i,n) {
    cin >> ss[i];
  }
  int inside_count = 0;
  int head_count = 0, tail_count = 0;
  int both_count = 0;
  REP(i,n) {
    string s;
    s = ss[i];
    if(s[0] == 'B' && s[s.size()-1] == 'A') ++both_count;
    else if(s[0] == 'B') ++head_count;
    else if(s[s.size()-1] == 'A') ++tail_count;
    inside_count += CountAB(s);
  }
  if(head_count+tail_count == 0) {
    cout << inside_count + max(0LL, both_count-1);
  } else {
    cout << inside_count + both_count + min(head_count, tail_count);
  }
  cout << "\n";
  return 0;
}
/***** MAIN *****/
