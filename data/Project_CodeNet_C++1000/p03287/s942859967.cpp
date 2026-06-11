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

ll N, M;
ll A[int(1e5 + 5)], sum[int(1e5 + 5)];
map<ll, ll> mp;

int main(){
  scanf("%lld%lld", &N, &M);
  mp[0]++;
  for (int i = 1; i <= N; i++){
    scanf("%lld", A+i);
    sum[i] = sum[i-1] + A[i];
    sum[i] %= M;
    mp[sum[i]]++;
  }


  ll ans = 0;
  for (int i = 0; i <= N; i++){
    mp[sum[i]]--;
    ans += mp[sum[i]];
  }
  cout << ans << endl;

  return 0;
}
