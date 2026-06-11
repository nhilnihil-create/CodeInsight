#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, y;
  cin >> n >> y;
  y /= 1000;
  rep(a,0,n+1) rep(b,0,n+1) {
    if (a + b > n) continue;
    int c = n - a - b;
    if (10*a + b*5 + c == y) {
      printf("%d %d %d\n", a, b, c);
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}