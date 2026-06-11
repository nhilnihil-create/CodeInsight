//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

ll AN(ll A, ll N){
  if (N == 0) return 1;
  else{
    if (N % 2 == 0){
      return AN(A * A % nmax, N / 2) % nmax;
    }else{
      return A * AN(A * A % nmax, N / 2) % nmax;
    }
  }
}

int main(){
  string S; cin >> S;
  ll DP[S.length() + 1][4];
  DP[0][0] = 1; DP[0][1] = 0; DP[0][2] = 0; DP[0][3] = 0;

  ll cnt = 0;
  for (int i = 0; i < S.length(); i++){
    
    for (int j = 0; j < 4; j++){
      DP[i + 1][j] = DP[i][j];
    }

    if (S[i] == 'A'){
      DP[i + 1][1] = DP[i][0] + DP[i][1];
    }else if (S[i] == 'B'){
      DP[i + 1][2] = DP[i][1] + DP[i][2];
    }else if (S[i] == 'C'){
      DP[i + 1][3] = DP[i][2] + DP[i][3];
    }else{
      cnt++;
      DP[i + 1][1] = DP[i][0] + DP[i][1] * 3; 
      DP[i + 1][2] = DP[i][1] + DP[i][2] * 3;
      DP[i + 1][3] = DP[i][2] + DP[i][3] * 3;
    }

    DP[i + 1][0] = AN(3, cnt);
    
    for (int j = 0; j < 4; j++){
      DP[i + 1][j] %= nmax;
    }
  }

  cout << DP[S.length()][3] << endl;

  return 0;
}
