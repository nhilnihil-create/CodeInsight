#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const int N = 100005;

void add_self(int &a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
}

void sub_self(int &a, int b){
	a -= b;
	if(a < 0)
		a += mod;
}

int main(){
	fastio;
	int n, k;
	cin >> n >> k;
	vi lim(n), dp(k+1);
	for(int i = 0; i < n; i++)
		cin >> lim[i];
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		vi pref(k+1);
		for(int used = k; used >= 0; used--){
			int value = dp[used];
			int l = used + 1;
			int r = used + min(lim[i], k-used);
			if(l <= r){
				add_self(pref[l], value);
				if(r+1 <= k)
					sub_self(pref[r+1], value);
			}
			/*for(int now = 1; now <= min(lim[i], k-used); now++){
				dp[used + now] += dp[used];
			}*/
		}
		int sum = 0;
		for(int i = 0; i <= k; i++){
			add_self(sum, pref[i]);
			add_self(dp[i], sum);
		}
	}
	cout << dp[k] << '\n';
	return 0;
}
