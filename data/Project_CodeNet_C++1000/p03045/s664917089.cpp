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

int N, M, X, Y, Z;
int Group[int(1e5 + 5)];

int Unite(){
  int GX = Group[X], GY = Group[Y];
  while (GX != Group[GX]) GX = Group[GX];
  while (GY != Group[GY]) GY = Group[GY];

  int G = min(GX, GY);
  Group[max(GX, GY)] = G;
  Group[X] = G; Group[Y] = G;
  return 0;
}

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) Group[i] = i;

  for (int i = 0; i < M; i++){
    scanf("%d%d%d", &X, &Y, &Z);
    Unite();
  }

  int ans = 0;
  for (int i = 1; i <= N; i++){
    int Gi = Group[i];
    while (Gi != Group[Gi]) Gi = Group[Gi];
    if (i == Gi) ans++;
  }
  printf("%d\n", ans);

  return 0;
}
