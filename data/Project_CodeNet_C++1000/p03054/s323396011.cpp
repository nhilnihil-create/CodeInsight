#include <bits/stdc++.h>

using namespace std;

int main(void) {

  int H, W, N;
  cin >> H >> W >> N;

  int sr, sc;
  cin >> sr >> sc;

  int Pos[4], Lim[4];
  Pos[0] = sr - 1;
  Pos[1] = sc - 1;
  Pos[2] = W - sc;
  Pos[3] = H - sr;
  Lim[0] = H;
  Lim[1] = W;
  Lim[2] = W;
  Lim[3] = H;

  string S, T;
  cin >> S >> T;

  for (int i = 0; i < N; i++) {
    
    Pos[S[i]%5]--;
    if (Pos[S[i]%5] < 0) {
      cout << "NO" << endl;
      return 0;
    }

    if (Pos[(T[i]%5)^3]+1 != Lim[(T[i]%5)^3]) {
      Pos[(T[i]%5)^3]++;
    }
  }

  cout << "YES" << endl;

  return 0;
}