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
    ll n, X;
    cin >> n >> X;
    vi x(n+1);
    rep(i, n) cin >> x[i];
    x[n] = X;
    sort(all(x));
    ll mini = INF;
    for (ll i = 1; i <= n;i++){
        chmin(mini, x[i] - x[i - 1]);
    }
    ll ans;
    for (ll i = mini; i > 0; i--){
        bool z = true;
        ll mod = x[0] % i;
        rep(j,n+1){
            if(x[j]%i!=mod)z = false;
        }
        if(z){
            ans = i;
            break;
        }
    }
    print(ans);
}