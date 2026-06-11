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

  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  int B[N]={0};
  int flag = 0;
  for(int i = N;i>=1;i--){
    REP(j,i){
      if(A[i-1-j]==i-1-j+1){
        FOR(k,i-1-j,i-1){
          A[k]=A[k+1];
        }
        B[i-1]=i-j;
        break;
      }else if(j==i-1){
        flag = 1;
      }
    }
  }

  if(flag == 1){
    cout << -1 << endl;
  }else{
    REP(i,N){
      cout << B[i] << endl;
    }
  }
}