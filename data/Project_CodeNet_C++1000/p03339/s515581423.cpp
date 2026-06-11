#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;

  string S;
  cin >> S;

  int E[N]={0};
  int W[N]={0};
  int wcnt=0;
  FOR(i,1,N){
    if(S.at(i-1)=='W'){
      wcnt++;
    }
    W[i]=wcnt;
  }
  int ecnt=0;
  for(int i=N-2;i>=0;i--){
    if(S.at(i+1)=='E'){
      ecnt++;
    }
    E[i]=ecnt;
  }

  int MIN = INF;
  REP(i,N){
    MIN = min(MIN,W[i]+E[i]);
  }

  cout << MIN << endl;
}