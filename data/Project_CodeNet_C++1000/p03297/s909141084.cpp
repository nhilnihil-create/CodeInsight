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

ll A, B, C, D;

ll GCD(ll M, ll m){
  if (M < m) swap(M, m);
  while (M % m != 0){
    M = M % m;
    swap(M, m);
  }
  return m;
}
bool Solve(){
  if (A < B) return false;
  if (B > D) return false;
  if (B <= C) return true;

  ll G = GCD(B, D);
  ll now = B - G + (A % G);

  if (now > C) return false;
  return true;
}

int main(){
  ll T; cin >> T;

  for (int i = 0; i < T; i++){
    cin >> A >> B >> C >> D;
    if (Solve() == false) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  

  return 0;
}