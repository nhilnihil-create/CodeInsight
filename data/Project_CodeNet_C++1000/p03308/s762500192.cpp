#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;


#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define asd cout << "ok" << endl;


#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define trav(it, m) for(auto it = m.begin(); it!= m.end(); it++)

const int MOD = 1e9 + 7;
const ll INF = 1e19;
const ld PI = acos((ld)-1);
const int MX = 2e5 +5;
const char nl = '\n';


int main(){

  int n; cin >> n;
  int a[n];
  for(int i= 0; i < n; i++){
    cin >> a[i];
  }
  int ans  = 0;
  for(int i = 0 ; i < n -1; i++){
    for(int j = i+1; j < n; j++)
    {
      ans = max(ans, abs(a[j] - a[i]));
    }
  }
  cout << ans << nl;




  return 0;
}

















