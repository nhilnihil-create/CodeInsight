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
  int N,M;
  cin >> N >> M;
  vector<P> A(M);
  vector<P> B(M);
  REP(i,M){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    B[i].first=A[i].second;
    B[i].second=A[i].first;
  }
  int x=-1;
  sort(ALL(B));
  int cnt = 0;
  REP(i,M){
    if(x==-1){
      x=B[i].first;
      cnt++;
    }else if(x<=B[i].second){
      x=B[i].first;
      cnt++;
    }
  }

  cout << cnt << endl;
}