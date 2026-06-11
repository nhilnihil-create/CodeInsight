#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;



int main() {
  int N, M;
  cin >> N >> M;


  vector<vector<int>> order(M,vector<int>(2));
  REP(m,M) cin >> order[m][0] >> order[m][1];  
  sort(order.begin(),order.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[1] < beta[1];});

  int befor=-100;
  int ans = 0;
  REP(m,M){
    int left  = order[m][0];
    int right = order[m][1];
    if (left <= befor && befor < right){
      // do nothing
    } else{
      befor = right - 1;
      ans += 1;
    }
  }
  cout << ans << endl;
}
