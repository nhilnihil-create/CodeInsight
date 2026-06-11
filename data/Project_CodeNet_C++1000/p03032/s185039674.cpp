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

int N, K;
ll V[55], ans = 0;

int main(){
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%lld", V + i);

  for (int L = 0; L <= min(N, K); L++){
    for (int R = 0; L + R <= min(N, K); R++){

      priority_queue <ll, vector<ll>, greater<ll> > que;
      ll now = 0;
      for (int i = 0; i < L; i++){
        now += V[i];
        if (V[i] < 0) que.push(V[i]);
      }
      for (int i = 0; i < R; i++){
        now += V[N - 1 - i];
        if (V[N - 1 - i] < 0) que.push(V[N - 1 - i]);
      }

      int cnt = 0;
      while (!que.empty() && cnt < K - (L + R)){
        ll Q = que.top(); que.pop();
        cnt++;
        now -= Q;
      }
      ans = max(ans, now);
    }
  }
  cout << ans << endl;


  return 0;
}
