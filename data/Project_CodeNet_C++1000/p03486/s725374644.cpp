#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<int>());
  if(t<=s){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}