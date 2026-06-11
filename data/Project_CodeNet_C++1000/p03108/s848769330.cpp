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

ll N, M, ans[int(1e5 + 5)];
Pii Graph[int(1e5 + 5)];
int Group[int(1e5 + 5)], Count[int(1e5 + 5)];

int main(){
  scanf("%lld%lld", &N, &M);
  for (int i = 0; i < M; i++){
    int A, B; scanf("%d%d", &A, &B);
    A--; B--;
    Graph[i] = mp(A, B);
  }
  for (int i = 0; i < N; i++){
    Group[i] = i; Count[i] = 1;
  }
  
  for (int i = M - 1; i >= 0; i--){
    ans[i] = ans[i + 1];
    int A = Graph[i].fi, B = Graph[i].se;
    int GA = Group[A], GB = Group[B];
    while (GA != Group[GA]) GA = Group[GA];
    while (GB != Group[GB]) GB = Group[GB];

    if (GA == GB) continue;
    ans[i] += Count[GA] * Count[GB];
    Count[min(GA, GB)] += Count[max(GA, GB)];
    Group[max(GA, GB)] = min(GA, GB);
  }

  for (int i = 1; i <= M; i++){
    printf("%lld\n", N * (N - 1) / 2 - ans[i]);
  }
  
  return 0;
}
