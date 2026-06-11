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
int C[200001], index[200001];
ll DP[200001];

int Solve(){
  for (int i = 1; i < N; i++){
    DP[i] = DP[i - 1];
    if (index[C[i]] != -1 && index[C[i]] != i - 1){
      DP[i] += DP[index[C[i]]];
    }
    DP[i] %= nmax;
    index[C[i]] = i;
  }
  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> C[i];
  fill(index, index + 200001, -1);
  DP[0] = 1; index[C[0]] = 0;
  Solve();
  cout << DP[N - 1] << endl;
  
  return 0;
}