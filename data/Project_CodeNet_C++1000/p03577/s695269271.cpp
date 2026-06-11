#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for(ll i = 0;i < n;i++)
template<class T, class U> void cmax(T& a, U b) { if (a<b) a = b; }
template<class T, class U> void cmin(T& a, U b) { if (a>b) a = b; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  string s;
  cin >> s;
  string f = "FESTIVAL";
  cout << s.substr(0, s.size()-f.size()) << endl;
}
