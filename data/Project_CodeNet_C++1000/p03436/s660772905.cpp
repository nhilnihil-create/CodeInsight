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

 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int H, W, cnt, Dist[55][55];
char S[55][55];

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int Calc_Dist(){
  fill((int*)Dist, (int*)(Dist + H), -1);
  Dist[0][0] = 0;
  queue <Pii> que; que.push({0, 0});
  while (!que.empty()){
    Pii Q = que.front(); que.pop();
    for (int k = 0; k < 4; k++){
      int I = Q.fi + di[k], J = Q.se + dj[k];
      if (I < 0 || H <= I || J < 0 || W <= J) continue;
      if (S[I][J] == '#') continue;
      if (Dist[I][J] != -1) continue;
      Dist[I][J] = Dist[Q.fi][Q.se] + 1;
      que.push({I, J});
    }
  }
  return 0;
}

int main(){
  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s", S + i);
    for (int j = 0; j < W; j++){
      if (S[i][j] == '#') cnt++;
    }
  }
  Calc_Dist();

  if (Dist[H - 1][W - 1] == -1){
    printf("-1\n");
  }else{
    printf("%d\n", H * W - 1 - cnt - Dist[H - 1][W - 1]);
  }

  return 0;
}
