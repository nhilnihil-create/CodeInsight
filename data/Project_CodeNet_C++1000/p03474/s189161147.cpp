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
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  bool t = true;
  REP(i,A+B+1){
    if(i==A){
      if (S[i] != '-') t = false;
      continue;
    }
    if('0'<=S[i]&&S[i]<='9'){

    }else{
      t = false;
    }
  }
  if (t) cout << "Yes" << endl;
  else
    cout << "No" << endl;
}