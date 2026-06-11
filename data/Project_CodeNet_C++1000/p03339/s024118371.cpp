#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  int ans = N;
  int sumE = 0;
  int sumW = 0;

  for(int i=1; i<N; i++){  //(0)がリーダー
    if(S.at(i)=='E') sumE++;
  }
  ans = min(sumE, ans);   
  for(int i=1; i<N; i++){ //(1からNがリーダー
    if(S.at(i-1) == 'W') sumW++;
    if(S.at(i) == 'E') sumE--;
    int tans = sumE + sumW;
    ans = min(tans, ans);
  }
  cout << ans << endl;
  return 0;
}