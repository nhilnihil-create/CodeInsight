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

int N, M;
priority_queue <ll> que;
Pll CB[int(1e5 + 5)];

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++){
    int A; scanf("%d", &A);
    que.push(A);
  }

  for (int i = 0; i < M; i++){
    ll B, C; scanf("%lld%lld", &B, &C);
    CB[i] = {C, B};
  }
  sort(CB, CB + M, greater<Pll>());

  ll cnt = 0;
  for (int i = 0; i < M; i++){
    cnt += CB[i].se;
    for (int j = 0; j < CB[i].se; j++) que.push(CB[i].fi);
    if (cnt >= N) break;
  }

  ll ans = 0;
  for (int i = 0; i < N; i++){
    ll now = que.top(); que.pop();
    ans += now;
  }
  cout << ans << endl;

  return 0;
}
