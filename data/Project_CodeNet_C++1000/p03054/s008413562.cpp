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

  int H, W, N; cin >> H >> W >> N;
  int sr, sc; cin >> sr >> sc;

  string S, T; cin >> S >> T;

  int U = 1, D = H;
  for (int i = N - 1; i >= 0; i--){
    if (T[i] == 'U') D = min(H, D + 1);
    else if (T[i] == 'D') U = max(1, U - 1);

    if (S[i] == 'U') U++;
    else if(S[i] == 'D') D--;

    if (U > D || U > H || D < 1){
      cout << "NO" << endl;
      return 0;
    } 
  }
  if (sr < U || D < sr){
    cout << "NO" << endl;
    return 0;
  }
  

  int L = 1, R = W;
  for (int i = N - 1; i >= 0; i--){
    if (T[i] == 'L') R = min(W, R + 1);
    else if(T[i] == 'R') L = max(1, L - 1);

    if (S[i] == 'L') L++;
    else if (S[i] == 'R') R--;

    if (L > R || L > W || R < 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  if (sc < L || R < sc){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  return 0;
}