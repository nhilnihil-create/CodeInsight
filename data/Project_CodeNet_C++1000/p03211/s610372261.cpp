#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vstr;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define asd cout << "ok" << endl;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define trav(it, m) for(auto it = m.begin(); it it!= m.end(); it++)

const char nl = '\n';
const int MOD = 1e9 +7;
const ll INF = 1e19;
const ld PI = acos((ld)-1);
const int MX = 2e5 + 5;

int main(){

  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int ans = 1e9;
  for(int i = 0; i <= s.size() - 3;i++)
  {
    int tmp = (s[i] - '0')*100 + (s[i+1] - '0')*10+(s[i+2] - '0');
    ans = min(ans, abs(tmp - 753));
  }
  cout << ans << nl;







  return 0;
}

