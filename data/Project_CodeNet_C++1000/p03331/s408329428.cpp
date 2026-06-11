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

int cnt[int(1e5 + 5)];

int Sum(int num){
  int ans = 0;
  while (num > 0) ans += num % 10, num /= 10;
  return ans;
}

int main(){
  int N; cin >> N;
  for (int i = 0; i <= N; i++) cnt[i] = Sum(i);

  int ans = N;
  for (int i = 1; i < N; i++){
    ans = min(ans, cnt[i] + cnt[N - i]);
  }
  cout << ans << endl;

  return 0;
}
