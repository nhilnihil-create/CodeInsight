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
  string S; cin >> S;
  int ans = 0;

  int L = 0, R = S.length() - 1;
  while (R - L > 0){
    if (S[L] == S[R]){
      L++; R--;
      continue;
    }

    if (S[L] == 'x' || S[R] == 'x'){
      ans++;
      if (S[L] == 'x') L++;
      else R--;
      continue;
    }
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
