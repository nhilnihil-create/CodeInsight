#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;

int main() {
  int N;
  cin >> N;
  vector<int> C(N-1);
  vector<int> S(N-1);
  vector<int> F(N-1);

  REP(n,N-1){
    cin >> C[n] >> S[n] >> F[n];
  }

  REP(n,N-1){
    int time = 0;

    for(int m = n;m < N-1;m++){
      if (time < S[m]) {
        time = S[m];
      } else if(time % F[m] == 0) {
        time = time;
      } else{
        time = time + F[m] - time%F[m];
      }
      time += C[m];  
      
    }
    cout << time << endl;

  }

  cout << 0 << endl;

}
