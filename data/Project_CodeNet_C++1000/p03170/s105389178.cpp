#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using ll=long long;
using ld=long double;
#define INF 1000000009
const ll INFll=1ll*INF*INF;
#define MOD 998244353
#define MODE 1000000007
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define pb push_back
#define mp make_pair
#define rep(i,n) for (ll i = 0; i < n; i++)
#define rev(i,n) for (ll i = n-1; i >= 0; i--)
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REV(i,a,b) for (ll i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define vl vector<ll>
#define pll pair<ll,ll>
#define sz(a) (ll)a.size()
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << ' '; cout << endl;
#define printii(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << it->f<<' '<<it->s << endl; cout << endl;
#define MID(i,j) ((i)+(j))/2
#define nl '\n' 
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define int ll
ll gcd(ll a,ll b)  {return (b==0)? a:gcd(b,a%b);}

ll bpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)res = res * a % m;
    a = a * a % m;
    b >>= 1;
}
return res;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<bool>dp(m+1);
    for(int i = 0; i < m+1; i++){
        for(int x : v){
            if(i >= x && !dp[i-x])dp[i] = 1;
        }
    }
    if(dp[m] == 0){
        cout << "Second" << endl;
    }
    else{
        cout << "First" << endl;
    }

}

// DONT GET TLE FOR NOT USING FASTIO (--__--)

signed main(){
	fastio;
    ll t = 1;
    // cin >> t;
    rep(i, t){
        solve();
    }
    return 0;
}
