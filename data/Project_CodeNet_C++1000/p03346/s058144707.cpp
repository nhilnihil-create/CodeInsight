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
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int main(){
  int N; cin >> N;
  int A[N], Count[N + 1] = {};
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = 0; i < N; i++){
    Count[A[i]] = Count[A[i] - 1] + 1;
  }
  
  int ans = 0;
  for (int i = 0; i < N + 1; i++){
    ans = max(ans, Count[i]);
  }
  cout << N - ans << endl;
  
  return 0;
}
