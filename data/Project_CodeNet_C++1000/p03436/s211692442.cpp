//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second
#define mp make_pair
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int H, W, Dist[55][55], ans;
char C[55][55];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main(){
  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; i++) scanf("%s", &C[i]);

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (C[i][j] == '.') ans++;
    }
  }
  
  Dist[0][0] = 1;
  queue <Pii> que; que.push(mp(0, 0));
  while (!que.empty()){
    Pii Q = que.front(); que.pop();
    for (int k = 0; k < 4; k++){
      int i = Q.fi + di[k], j = Q.se + dj[k];
      if (0 <= i && i < H && 0 <= j && j < W){
        if (Dist[i][j] == 0 && C[i][j] != '#'){
          Dist[i][j] = Dist[Q.fi][Q.se] + 1;
          que.push(mp(i, j));
        }
      }
    }
  }
  
  if (Dist[H - 1][W - 1] == 0){
    cout << -1 << endl;
  }else{
    cout << ans - Dist[H - 1][W - 1] << endl;
  }

  return 0;
}
