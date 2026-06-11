#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpii = vector<pll>;

int main(){
  ll H, W;
  cin >> H >> W;
  vvl A(H, vl(W, 0));
  string row;
  queue<vl> que;
  rep(i, H){
    cin >> row;
    rep(j, W){
      if(row[j] == '#'){
        A[i][j] = 1;
        que.push({i, j});
      }
    }
  }

  ll cnt = 0;
  vl frt, bck;

  while(true){
    bck = que.back();

    while(true){
      frt = que.front();
      que.pop();

      if((frt[0] > 0) && (A[frt[0] - 1][frt[1]] == 0)){
        A[frt[0] - 1][frt[1]] = 1;
        que.push({frt[0] - 1, frt[1]});
      }
      if((frt[0] < H - 1) && (A[frt[0] + 1][frt[1]] == 0)){
        A[frt[0] + 1][frt[1]] = 1;
        que.push({frt[0] + 1, frt[1]});
      }
      if((frt[1] > 0) && (A[frt[0]][frt[1] - 1] == 0)){
        A[frt[0]][frt[1] - 1] = 1;
        que.push({frt[0], frt[1] - 1});
      }
      if((frt[1] < W - 1) && (A[frt[0]][frt[1] + 1] == 0)){
        A[frt[0]][frt[1] + 1] = 1;
        que.push({frt[0], frt[1] + 1});
      }
	
      if((bck[0] == frt[0]) && (bck[1] == frt[1])) break;
    }

    if(que.empty()) break;
    cnt++;
  }

  cout << cnt << endl;
  
  return 0;
}