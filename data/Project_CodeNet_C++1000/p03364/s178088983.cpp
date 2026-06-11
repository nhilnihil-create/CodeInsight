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
  char C[N][N];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> C[i][j];
    }
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++){
    char C2[N][N];
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        if (i + j < N) C2[j][k] = C[i + j][k];
        else C2[j][k] = C[i + j - N][k];
      }
    }

    bool flag = true;

    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        if (C2[j][k] != C2[k][j]) flag = false;
      }
    }
    
    if (flag == true) ans++;
  }
  cout << ans * N << endl;

  return 0;
}