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
  int N;
  cin >> N;
  vector<string> W(N);
  REP(i, N) cin >> W[i];
  
  int flag = 0;
  FOR(i,1,N){
    REP(j,i){
      if(W.at(j)==W.at(i)){
        flag = 1;
      }
    }
    if(W.at(i).at(0) != W.at(i-1).at(W.at(i-1).size()-1)){
      flag = 1;
    }
  }

  if(flag == 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}