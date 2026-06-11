#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];

  sort(RALL(A));
  int apoint = 0;
  int bpoint = 0;
  for(int i = 0; i < N; i += 2) apoint += A[i];
  for(int i = 1; i < N; i += 2) bpoint += A[i];

  cout << apoint - bpoint << endl;

  return 0;
}

