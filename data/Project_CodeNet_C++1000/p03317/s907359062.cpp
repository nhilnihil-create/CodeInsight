#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll mini = INF;
    rep(i, n){
        cin >> a[i];
        chmin(mini, a[i]);
    }
    ll ans = 0;
    ll tmp = 0;
    for(ll i=1;i<n;i++){
      if(a[i-1]==mini&&a[i]!=mini){
          a[i] = mini;
          tmp++;
          if(tmp==k-1){
              tmp = 0;
              ans++;
          }
      }
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        if(a[i+1]==mini&&a[i]!=mini){
            a[i] = mini;
            tmp++;
            if(tmp==k-1){
              tmp = 0;
              ans++;
          }
        }
    }
    if (tmp > 0)ans++;
    print(ans);
}