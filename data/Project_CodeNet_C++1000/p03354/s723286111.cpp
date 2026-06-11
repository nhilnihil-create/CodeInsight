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
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, M, P[int(1e5 + 5)];
int X, Y, UF[int(1e5 + 5)];

int Unite(){
  int UX = UF[X], UY = UF[Y];
  while (UX != UF[UX]) UX = UF[UX];
  while (UY != UF[UY]) UY = UF[UY];

  UF[max(UX, UY)] = min(UX, UY);
  UF[X] = min(UX, UY);
  UF[Y] = min(UX, UY);
  return 0;
}

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) UF[i] = i, scanf("%d", P + i);

  for (int i = 0; i < M; i++){
    scanf("%d%d", &X, &Y); Unite();
  }

  int ans = 0;
  for (int i = 1; i <= N; i++){
    int G = UF[i];
    while (G != UF[G]) G = UF[G];
    UF[i] = G;
  }

  for (int i = 1; i <= N; i++){
    if (UF[i] == UF[P[i]]) ans++;
  }

  printf("%d\n", ans);

  return 0;
}
