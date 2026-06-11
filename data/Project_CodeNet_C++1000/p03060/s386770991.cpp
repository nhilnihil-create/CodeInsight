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
  int n; cin >> n;
  int ans = 0;
  vi v(n), c(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  for(int i = 0; i < n; i++)
    cin >> c[i];
  for(int i =0; i <n; i++){
    if(v[i] > c[i])
      ans += v[i] - c[i];
  }
  cout << ans << nl;


}
