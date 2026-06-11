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
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<P> A(M);
  REP(i,M){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
  }
  vector<P> B(Q);
  REP(i,Q){
    cin >> B[i].first >> B[i].second;
    B[i].first--;
    B[i].second--;
  }
  
  vector<vector<int>> vec(N+1,vector<int> (N+1,0));
  REP(i,M){
    vec[0][A[i].second]++;
    vec[A[i].first+1][A[i].second]--;
    vec[0][N]--;
    vec[A[i].first+1][N]++;
  }

  REP(i,N+1){
    int sum=0;
    REP(j,N+1){
      sum+=vec[i][j];
      vec[i][j]=sum;
    }
  }
  REP(j,N+1){
    int sum=0;
    REP(i,N+1){
      sum+=vec[i][j];
      vec[i][j]=sum;
    }
  }

  REP(i,Q){
    cout << vec[B[i].first][B[i].second] << endl;
  }
}