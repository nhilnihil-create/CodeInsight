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

int N;
ll A[int(1e5 + 5)], B[int(1e5 + 5)];
ll deg[int(1e5 + 5)];
bool visited[int(1e5 + 5)];

int main(){
  cin >> N;
  ll suma = 0, sumb = 0;
  for (int i = 0; i < N; i++) cin >> A[i], suma += A[i];
  for (int i = 0; i < N; i++) cin >> B[i], sumb += B[i];

  if (suma < sumb){
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < N; i++){
    deg[i] = A[i] - B[i];
  }
  sort(deg, deg + N);

  int ans = 0, R = N - 1;
  for (int i = 0; i < N; i++){
    if (deg[i] >= 0) break;
    ans++;
    while (deg[i] < 0){
      if (!visited[R]){
        ans++; visited[R] = true;
      }
      if (deg[i] + deg[R] >= 0){
        deg[R] += deg[i];
        deg[i] = 0;
        continue;
      }else{
        deg[i] += deg[R];
        R--;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
