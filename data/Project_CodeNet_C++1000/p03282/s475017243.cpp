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
  string S;
  ll K;
  cin >> S >> K;
  int flag = 0;
  REP(i,S.size()){
    if(S.at(i) != '1'){
      if(i<K){
        cout << S.at(i) << endl;
      }else{
        cout << 1 << endl;
      }
      flag = 1;
      break;
    }
  }
  if(flag == 0){
    cout << 1 << endl;
  }
}