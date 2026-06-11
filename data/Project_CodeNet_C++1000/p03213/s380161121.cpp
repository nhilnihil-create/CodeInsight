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
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int N;
ll Prime_Count[100], Count[75];

int main(){
  cin >> N;
  for (int i = 2; i <= N; i++){
    int num = i;
    for (int j = 2; j <= i; j++){
      while (num % j == 0){
        Prime_Count[j]++;
        num /= j;
      }
    }
  }

  for (int i = 0; i < 100; i++){
    if (Prime_Count[i] >= 75) Count[74]++;
    else Count[Prime_Count[i]]++;
  }
  
  for (int i = 73; i >= 2; i--){
    Count[i] += Count[i + 1];
  }


  ll ans = Count[74];
  ans += Count[24] * (Count[2] - 1);
  ans += Count[14] * (Count[4] - 1);
  ans += Count[4] * (Count[4] - 1) * (Count[2] - 2) / 2;
  cout << ans << endl;

  return 0;
}
