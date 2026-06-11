#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pvec(v) for(auto e: v) cout << e << " ";
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b) for(int i = (a); i<(b); ++i)
#define pb push_back
#define INF 1000000005
#define MOD 1000000007
#define all(v) v.begin(), v.end()

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll power(ll x, ll y, ll p = MOD){  
    ll res = 1LL; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1LL)  
            res = (res*x) % p;
        y = y>>1LL; 
        x = (x*x) % p;  
    }  
    return res;  
}  

int main(){
	IO
	int n;
	cin >> n;

	int h[n];
	for(int i = 0; i<n; ++i) {
		cin >> h[i];
	}

	int dp[n + 1] = {0};
	dp[2] = abs(h[1] - h[0]);
	for(int i = 3; i <= n; ++i) {
		dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i - 2]) , dp[i - 2] + abs(h[i - 1] - h[i - 3]));
	}

	cout << dp[n] << endl;
	return 0;
}