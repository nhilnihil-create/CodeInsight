#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  vector<P> B(N);
  REP(i,N) cin >> B[i].first >> B[i].second;
  
  sort(ALL(A));
  sort(ALL(B));
  vector<bool> Ab(N,false);
  int ans = 0;
  REP(i,N){
    int MAXAY=-1;
    int MAXA=-1;
    REP(j,N){
      if(B[i].first<=A[j].first) break;
      if(Ab[j]!=false) continue;
      if(MAXAY<A[j].second&&A[j].second<B[i].second){
        MAXAY=A[j].second;
        MAXA=j;
      }
    }
    if(MAXA!=-1){
      ans++;
      Ab[MAXA]=true;
    }
  }

  cout << ans << endl;
}