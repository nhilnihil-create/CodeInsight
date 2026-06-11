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

int N, M, Q, L, R;
int DP[501][501], Sum[501][501];

int main(){
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < M; i++){
    scanf("%d%d", &L, &R);
    DP[L][R]++;
  }

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1];
      Sum[i][j] += DP[i][j];
    }
  }
  
  for (int i = 0; i < Q; i++){
    int p, q; scanf("%d%d", &p, &q);
    printf("%d\n", Sum[q][q] - Sum[p-1][q] - Sum[q][p-1] + Sum[p-1][p-1]);
  }
  
  return 0;
}
