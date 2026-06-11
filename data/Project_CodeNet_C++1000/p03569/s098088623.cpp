#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  string subS;
  vector <int> P;
  
  int cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'x') {
      cnt++;
    } else {
      subS += S[i];
      P.push_back(cnt);
      cnt = 0;
    }
    
    if (i == S.size()-1) {
      if (S[i] == 'x') {
        P.push_back(cnt);
      } else {
        P.push_back(0);
      }
    }
  }
  
//  cout << subS << endl;

/*
  for (int i = 0; i < P.size(); i++) {
    cout << P[i] << " ";
  }
*/
  
  
  // subSの回文チェック
  int N = subS.size();
  for (int i = 0; i < N; i++) {
    if (subS[i] != subS[N-1-i]) {
      cout <<  -1 << endl;
      return 0;
    }
  }
  
  
  // Pを鏡対象に比較してmaxをとっていく
  int M = P.size();
  vector<int> MAX_mirrorP(M);

  for (int i = 0; i <= M /2; i++) {
    MAX_mirrorP[i] = max(P[i], P[M-1-i]);
    MAX_mirrorP[M-1-i] = max(P[i], P[M-1-i]);
  }
  
  int sum = 0;
  
  for (int i = 0; i < M; i++) {
    sum += MAX_mirrorP[i] - P[i];
  }
  cout << sum << endl;
}