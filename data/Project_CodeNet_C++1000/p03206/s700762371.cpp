#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int d;
  cin >> d;
  if(d==25)cout<<"Christmas"<<endl;
  else if(d==24)cout<<"Christmas Eve"<<endl;
  else if(d==23)cout<<"Christmas Eve Eve"<<endl;
  else if(d==22)cout<<"Christmas Eve Eve Eve"<<endl;
}
