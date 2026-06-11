//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>      // sqrt
#include <cstdlib>    // exit
#include <algorithm>  // min,max
using namespace std;
#define forr(i,m,n) for (int i=(m); i<=(n); i++)
#define forv(i,m,n) for (int i=(m); i>=(n); i--)
#define forall(it,p) for (auto it = p.begin(); it != p.end(); ++it)
#define R 1000000007
#define DBG 0
typedef pair<int,int> pii;

#define MAXN 300
int d[MAXN][MAXN];
int e[MAXN][MAXN];

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  forr(i,0,n-1)
    cin >> s[i];
  forr(i,0,n-1)
  forr(j,0,n-1) d[i][j] = e[i][j] = 0;

  int m = (n-1)/2;
  forr(i,0,n-1)
  forr(j,0,n-1) {
    int dend = m;
    int eend = (n%2 == 1 ? m-1 : m);
    int dd = 0;
    forr(k,1,dend)
      if (s[(i+k)%n][(j-k+n)%n]==s[(i-k+n)%n][(j+k)%n])
        dd = k;
      else break;
    d[i][j] = dd;
    int ee = -1;
    forr(k,0,eend)
      if (s[(i-k+n)%n][(j+k)%n]==s[(i+1+k)%n][(j-1-k+n)%n])
        ee = k;
      else break;
    e[i][j] = ee;
  }

  if (DBG) {
    cout << "d" << endl;
    forr(i,0,n-1) {
      forr(j,0,n-1) cout << d[i][j] << ' ';
      cout << endl;
    }
    cout << "e" << endl;
    forr(i,0,n-1) {
      forr(j,0,n-1) cout << e[i][j] << ' ';
      cout << endl;
    }
  }

  int cnt = 0;
  forr(i,0,n-1)
  forr(j,0,n-1) {
    bool ok = true;
    forr(k,0,n-1)
      if (d[(i+k)%n][(j+k)%n] < min(k,n-1-k)) {
        if (DBG) cout << "setfd k " << k << endl;
        ok = false;
        break;
      }
    forr(k,0,n-2)
        if (e[(i+k)%n][(j+1+k)%n] < min(k,n-2-k)) {
          if (DBG) cout << "setfe k " << k << endl;
          ok = false;
          break;
        }
    if (DBG) cout << "i " << i << " j " << j << " ok " << ok << endl;
    if (ok) cnt++;
  }

  cout << cnt << endl;
}
