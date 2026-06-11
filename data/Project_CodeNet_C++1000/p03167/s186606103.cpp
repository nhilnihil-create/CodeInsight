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
	int H, W;
	cin >> H >> W;

	char mat[H][W];
	string tmp;
	for(int i = 0; i<H; ++i) {
		cin >> tmp;
		for(int j = 0; j<W; ++j) {
			mat[i][j] = tmp[j];
		}
	}

	vll prev(W, 1), curr(W, 0);
	bool poss = true;
	for(int i = 0; i < W; ++i) {
		if(mat[0][i] == '#' && poss) {
			prev[i] = 0;
			poss = false;
		}
		if(!poss) 
			prev[i] = 0;
		// cout << prev[i] << " ";
	}
	// cout << endl;

	for(int i = 1; i<H; ++i) {
		if(mat[i][0] != '#') curr[0] = prev[0];
		else curr[0] = 0;
		
		for(int j = 1; j<W; ++j) {
			if(mat[i][j] == '#')
				curr[j] = 0;
			else
				curr[j] = (prev[j] + curr[j - 1])%MOD;
		}

		for(int j = 0; j < W; ++j) {
			// cout << curr[j] << " ";
			prev[j] = curr[j];
		}
		// cout << endl;
	}

	cout << prev[W - 1] << endl;
	return 0;
}