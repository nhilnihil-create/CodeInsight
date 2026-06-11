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
  ll N, M;
  cin >> N >> M;

  if(N!=1&&M!=1){
    cout << (N-2)*(M-2) << endl;
  }else if(N==1&&M!=1){
    cout << M-2 << endl;
  }else if(M==1&&N!=1){
    cout << N-2 << endl;
  }else{
    cout << 1 << endl;
  }
}