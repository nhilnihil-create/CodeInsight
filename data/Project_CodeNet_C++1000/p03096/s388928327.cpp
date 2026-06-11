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

int main(){
  int N; cin >> N;
  int C[N];
  for (int i = 0; i < N; i++) cin >> C[i];

  vector <int> Before_Index(2e5 + 1);
  fill(Before_Index.begin(), Before_Index.end(), -1);

  vector <ll> DP(N);
  DP[0] = 1; 
  Before_Index[C[0]] = 0;

  for (int i = 1; i < N; i++){
    DP[i] = DP[i - 1];
    DP[i] %= nmax;
    if (Before_Index[C[i]] == -1){
      Before_Index[C[i]] = i;
      continue;
    }
    if (C[i] == C[i - 1]){
      continue;
    }

    DP[i] += DP[Before_Index[C[i]]];
    Before_Index[C[i]] = i;
    DP[i] %= nmax;
  }
  cout << DP[N - 1] << endl;

  return 0;
}
