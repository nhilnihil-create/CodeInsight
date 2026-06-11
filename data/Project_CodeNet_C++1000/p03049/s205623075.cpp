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
  vector<string> A(N);
  REP(i, N) cin >> A[i];

  int cnt = 0;
  REP(i,N){
    REP(j,A[i].size()-1){
      if(A[i].at(j)=='A'&&A[i].at(j+1)=='B'){
        cnt++;
      }
    }
  }

  int cntBA=0;
  int cntA=0;
  int cntB=0;
  REP(i,N){
    if(A[i].at(0)=='B'&&A[i].at(A[i].size()-1)=='A'){
      cntBA++;
    }else if(A[i].at(0)=='B'){
      cntB++;
    }else if(A[i].at(A[i].size()-1)=='A'){
      cntA++;
    }
  }
  if(cntBA>=1){
    cnt+=cntBA-1;
    if(cntA>=1){
      cnt++;
      cntA--;
    }
    if(cntB>=1){
      cnt++;
      cntB--;
    }
    cnt+=min(cntA,cntB);
  }else if(cntBA==0){
    cnt+=min(cntA,cntB);
  }

  cout << cnt << endl;
}