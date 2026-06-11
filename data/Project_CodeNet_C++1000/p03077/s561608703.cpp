#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >>d >> e;
  ll x=min(min(min(a,b),min(c,d)),e);
  if(n%x)
    cout << n/x+5 << endl;
  else
    cout << n/x+4 << endl;
}