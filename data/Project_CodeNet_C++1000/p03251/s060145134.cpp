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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vi v1, v2;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    v1.pb(x);
  }
  for(int i = 0; i < m; i++){
    int x; cin >> x;
    v2.pb(x);
  }
  v1.pb(x);
  v2.pb(y);
  sort(all(v1));
  sort(all(v2));
  if(v1[v1.size()-1] < v2[0])
  {
    cout << "No War" << nl;
    return 0;
  }
  cout << "War" << nl;







  return 0;
}

