#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int D, N;
  cin >> D >> N;
  if(N!=100){
    if(D == 0){
      cout << N << endl;
    }else if(D == 1){
      cout << N*100 << endl;
    }else{
      cout << N*10000 << endl;
    }
  }else{
    if(D == 0){
      cout << N+1 << endl;
    }else if(D == 1){
      cout << (N+1)*100 << endl;
    }else{
      cout << (N+1)*10000 << endl;
    }
  }
}