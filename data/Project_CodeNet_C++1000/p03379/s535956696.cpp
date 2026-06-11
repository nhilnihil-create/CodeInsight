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
  vector<int> B(N);
  REP(i, N){
    cin >> A[i];
    B[i]=A[i];
  }
  
  sort(ALL(B));
  REP(i,N){
    if(A[i]>=B[N/2]){
      cout << B[N/2-1] << endl;
    }else{
      cout << B[N/2] << endl;
    }
  }
}