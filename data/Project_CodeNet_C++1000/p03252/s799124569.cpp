#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main(){ 
  string s, t;
  cin >> s >> t;
  int n = s.size();

  map<char, char> ss, tt;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    char a = s[i], b = t[i];

    if (ss.count(b)) if (ss[b] != a) ok = false;
    if (tt.count(a)) if (tt[a] != b) ok = false;
    ss[b] = a;
    tt[a] = b;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
} 