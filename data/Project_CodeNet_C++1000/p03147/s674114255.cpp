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

int N, H[105];

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", H + i);

  int ans = 0;
  int L = 0;
  
  while (true){
    bool flag = false;
    int L = 0, R = N;
    for (int i = 0; i < N; i++){
      if (H[i] > 0) {
        L = i, flag = true; break;
      }
    }
    if (!flag) break;

    int now = H[L];
    for (int i = L; i <= N; i++){
      if (H[i] == 0){
        R = i; break;
      }
      now = min(H[i], now);
    }
    ans += now;
    for (int i = L; i < R; i++) H[i] -= now;
  }
  cout << ans << endl;

  return 0;
}
