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

  if(N%2==1){
    cout << (N-1)*(N-1)/2 << endl;
    FOR(i,1,N+1){
      FOR(j,i+1,N+1){
        if(j!=N-i){
          cout << i << " " << j << endl;
        }
      }
    }
  }else{
    cout << (N-2)*N/2 << endl;
    FOR(i,1,N+1){
      FOR(j,i+1,N+1){
        if(j!=N-i+1){
          cout << i << " " << j << endl;
        }
      }
    }
  }
}