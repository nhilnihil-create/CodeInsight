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

int N, A[205], B[205], Count[205];
vector <int> Graph[205];

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d%d", A + i, B + i);
  }

  for (int i = 100; i < N + 100; i++){
    scanf("%d%d", A + i, B + i);
    for (int j = 0; j < N; j++){
      if (A[j] < A[i] && B[j] < B[i]){
        Graph[i].push_back(j);
        Graph[j].push_back(i);
        Count[i]++; Count[j]++;
      }
    }
  }

  int ans = 0, cnt = 0;
  while (cnt < N){
    cnt++;

    priority_queue <Pii, vector<Pii>, greater<Pii> > que;
    for (int i = 0; i < N; i++){
      if (Count[i] == 0) continue;
      que.push({Count[i], i});
    }
    for (int i = 100; i < N + 100; i++){
      if (Count[i] == 0) continue;
      que.push({Count[i], i});
    }

    if (que.empty()) break;

    int edge = que.top().se, next = -1, num = 1e9;
    Count[edge] = 0;

    for (int i = 0; i < Graph[edge].size(); i++){
      if (Count[Graph[edge][i]] == 0) continue;

      if (Count[Graph[edge][i]] < num){
        num = Count[Graph[edge][i]];
        next = Graph[edge][i];
      }
      Count[Graph[edge][i]]--;
    }
    if (next == -1) continue;
    ans++;
    Count[next] = 0;

    for (int i = 0; i < Graph[next].size(); i++){
      if (Count[Graph[next][i]] == 0) continue;
      Count[Graph[next][i]]--;
    }
  }
  cout << ans << endl;


  return 0;
}
