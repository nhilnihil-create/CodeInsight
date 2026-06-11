#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int n) {
  if (n%2 == 0) return n/2;
  return 3*n+1;
}

int main() {
  int s;
  cin >> s;
  vector<bool> a(1000100,false);
  a[s] = true;
  int m = 1;
  while(true) {
    s = f(s);
    m++;
    if (a[s]) break;
    a[s] = true;
  }
  cout << m << endl;
  return 0;
}
