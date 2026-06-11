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


int main(){
  int N; cin >> N;
  string S; cin >> S;
  int Q; cin >> Q;
  vector <int> K(Q);
  for (int i = 0; i < Q; i++) cin >> K[i];
  
  for (int i = 0; i < Q; i++){
    ll ans = 0;

    ll DP[N + 1][3];
    for (int j = 0; j < 3; j++){
      DP[0][j] = 0;
    }
    
    for (int j = 1; j < N + 1; j++){
      for (int k = 0; k < 3; k++){
        DP[j][k] = DP[j - 1][k];
      }

      if (j - K[i] > 0){
        if (S[j - K[i] - 1] == 'D'){
          DP[j][2] -= DP[j][1];
          DP[j][0]--;
        }else if (S[j - K[i] - 1] == 'M'){
          DP[j][1]--;
        }
      }
      
      if (S[j - 1] == 'D'){
        DP[j][0]++;
      }else if(S[j - 1] == 'M'){
        DP[j][1]++;
        DP[j][2] += DP[j][0];
      }else if(S[j - 1] == 'C'){
        ans += DP[j][2];
      }
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
