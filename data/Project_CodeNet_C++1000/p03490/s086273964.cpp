#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1LL << 60
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i, m) for (long long i = 0; i < m; i++)
#define FOR(i, n, m) for (long long i = n; i < m; i++)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
  string s;
  cin >> s;
  vector<int> vx, vy;
  bool f = true;
  int c = 0;
  REP(i, s.size()){
    if(f){
      if(s[i] == 'F') c++;
      else{
        f = false;
        vx.pb(c);
        c = 0;
      }
    }
    else{
      if(s[i] == 'F') c++;
      else{
        f = true;
        vy.pb(c);
        c = 0;
      }
    }
    if(i == (s.size()-1) && c != 0){
      if(f) vx.pb(c);
      else vy.pb(c);
    }
  }
  bitset<20001> x = 1, y = 1;
  x <<= 10000;
  y <<= 10000;
  if(s[0] == 'F') x <<= vx[0];
  REP(i, vx.size()){
    if(s[0] == 'F' && i == 0) continue;
    x = ((x << vx[i]) | (x >> vx[i]));
  }
  REP(i, vy.size()){
    y = ((y << vy[i]) | (y >> vy[i]));
  }
  int a, b;
  cin >> a >> b;
  if(x[10000+a] && y[10000+b]) cout << "Yes" << endl;
  else cout << "No" << endl;
	return 0;
}
