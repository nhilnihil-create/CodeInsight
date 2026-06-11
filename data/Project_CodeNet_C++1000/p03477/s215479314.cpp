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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c + d) cout << "Left" << endl;
  if (a + b == c + d) cout << "Balanced" << endl;
  if (a + b < c + d) cout << "Right" << endl;
  return 0;
}