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

int N, ans = 0;
int cnt[105];
bool visited[105];

int Add(int num){
  int now = num;
  for (int i = 2; i * i <= num; i++){
    while (now % i == 0){
      cnt[i]++;
      now /= i;
    }
  }
  if (now > 1) cnt[now]++;

  return 0;
}

int main(){
  scanf("%d", &N);

  for (int i = 2; i <= N; i++) Add(i);

  for (int i = 2; i <= N; i++){
    if (cnt[i] >= 74) ans++;
  }

  for (int i = 2; i <= N; i++){
    fill(visited, visited + 100, false);
    if (cnt[i] < 24) continue;
    visited[i] = true;
    for (int j = 2; j <= N; j++){
      if (!visited[j] && cnt[j] >= 2) ans++;
    }
  }

  for (int i = 2; i <= N; i++){
    fill(visited, visited + 100, false);
    if (cnt[i] < 14) continue;
    visited[i] = true;
    for (int j = 2; j <= N; j++){
      if (!visited[j] && cnt[j] >= 4) ans++;
    }
  }


  for (int i = 2; i <= N; i++){
    if (cnt[i] < 2) continue;
    int now = 0;
    for (int j = 2; j <= N; j++){
      if (i == j) continue;
      if (cnt[j] >= 4) now++;
    }
    ans += now * (now - 1) / 2;
  }

  cout << ans  << endl;

  return 0;
}
