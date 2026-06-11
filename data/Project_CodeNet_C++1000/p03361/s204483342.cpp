#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)

using namespace std;

bool check(vector<vector<char>> F, int h, int w) {
  if (F[h-1][w]=='#') return true;
  if (F[h][w-1]=='#') return true;
  if (F[h][w+1]=='#') return true;
  if (F[h+1][w]=='#') return true;
  else return false;
}

int main() {
  int H=0, W=0;
  cin >> H >> W;
  vector<vector<char>> F(H+2, vector<char>(W+2));
  rep(h, H+2){
    rep(w, W+2){
      F[h][w] = '.';
    }
  }
  rep(h, H){
    rep(w, W){
      cin >> F[h+1][w+1];
    }
  }

  bool flag = true;

  rep(h, H){
    rep(w, W){
      if (F[h+1][w+1] == '.') continue;
      else flag *= check(F, h+1, w+1);
    }
  }

  if (flag==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}