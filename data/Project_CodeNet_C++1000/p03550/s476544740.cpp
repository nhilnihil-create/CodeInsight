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

int N, Z, W, A[2005];
int DP[2005][2];

int Solve(int num, int turn){
  if (DP[num][turn] != -1) return DP[num][turn];

  if (turn == 0){
    int ans;
    if (num == 0) ans = abs(W - A[N - 1]);
    else ans = abs(A[num - 1] - A[N - 1]);
    for (int i = num + 1; i < N; i++){
      ans = max(ans, Solve(i, 1 - turn));
    }
    return DP[num][turn] = ans;
  }else{
    int ans = abs(A[num - 1] - A[N - 1]);
    for (int i = num + 1; i < N; i++){
      ans = min(ans, Solve(i, 1 - turn));
    }
    return DP[num][turn] = ans;
  }
}

int main(){
  scanf("%d%d%d", &N, &Z, &W);
  for (int i = 0; i < N; i++) scanf("%d", A + i);
  fill((int*)DP, (int*)(DP + N + 1), -1);

  cout << Solve(0, 0) << endl;

  return 0;
}
