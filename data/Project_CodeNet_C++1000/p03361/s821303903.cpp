#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
     ifstream in("input.txt");
     cin.rdbuf(in.rdbuf());
  //*/
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  bool bad = false;
  for(int i = 0; i < H; i++) cin >> S[i];
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(S[i][j] == '#'){
        if(!((i > 0 && S[i-1][j] == '#') || (i < H-1 && S[i+1][j] == '#')|| (j > 0 && S[i][j-1] == '#') || (j < W-1 && S[i][j+1] == '#'))) bad = true;
      }
    }
  }
  if(bad) cout <<"No"<<endl;
  else cout << "Yes" <<endl;
}
