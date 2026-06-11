#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define sbp(p, n) rep(i, n) { int a, b; scanf("%d %d", &a, &b); p[i] = make_pair(a, b); }
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}