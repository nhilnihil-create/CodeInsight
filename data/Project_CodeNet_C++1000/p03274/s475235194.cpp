#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;
  vector<ll> x(n);
  for(ll i = 0; i < n; i++) cin >> x[i];

  ll ans = INF;
  for(ll i = 0; i < n-k+1; i++){
    ll l = x[i], r = x[i+k-1];
    //cout << l << ' ' << r << endl;

    if(r <= 0) ans = min(ans, abs(l));
    else if(l < 0 && r > 0) ans = min(ans, abs(min(abs(r), abs(l))+r-l));
    else if(l >= 0) ans = min(ans, r);
  }
  cout << ans << endl;
  return 0;
}