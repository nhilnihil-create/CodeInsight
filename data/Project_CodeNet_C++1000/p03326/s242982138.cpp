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
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

int N, M;
ll X[1005][3], Score[1005];
bool now[3];

int Prepare(int num){
  fill(Score, Score + N, 0);
  for (int i = 0; i < 3; i++){
    now[i] = num % 2; num /= 2;
  }
  return 0;
}

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 3; j++){
      scanf("%lld", &X[i][j]);
    }
  }

  
  ll ans = 0;
  for (int i = 0; i < 8; i++){
    Prepare(i);
    for (int j = 0; j < N; j++){
      for (int k = 0; k < 3; k++){
        if (now[k]) Score[j] += X[j][k];
        else Score[j] -= X[j][k];
      }
    }
    sort(Score, Score + N, greater<ll>());

    ll sum = 0;
    for (int j = 0; j < M; j++){
      sum += Score[j];
    }
    ans = max(sum, ans);
  }
  cout << ans << endl;

  return 0;
}
