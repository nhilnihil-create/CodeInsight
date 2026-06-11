#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N_MAX = 1e5+1;

int H, W, N, sr, sc;
string S, T;

int pos[4];
unordered_map<char, int> taka;
unordered_map<char, int> aoki;

void solve(){
  taka['U'] = 0;
  taka['D'] = 1;
  taka['L'] = 2;
  taka['R'] = 3;

  aoki['U'] = 1;
  aoki['D'] = 0;
  aoki['L'] = 3;
  aoki['R'] = 2;

  bool clr = true;

  for(int i = 0; i < N; i++){
    int idx = taka[S[i]];
    int move = (idx % 2 == 0) ? -1 : 1;
    int lim = (idx <= 1) ? H : W;

    pos[idx] += move;
    if(pos[idx] <= 0 || pos[idx] > lim) clr = false;

    if(!clr) break;

    idx = aoki[T[i]];
    move = (idx % 2 == 0) ? 1 : -1;
    lim = (idx <= 1) ? H : W;

    if(pos[idx] + move > 0 && pos[idx] + move <= lim)
      pos[idx] += move;
  }
  cout << (clr ? "YES" : "NO") << endl;
}


int main() {

  cin >> H >> W >> N >> sr >> sc >> S >> T;
  pos[0] = pos[1] = sr;
  pos[2] = pos[3] = sc;

  solve();
}