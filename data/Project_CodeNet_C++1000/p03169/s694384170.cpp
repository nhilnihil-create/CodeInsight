///apigs property
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second
#define pb push_back
#define vll vector< ll >
#define vi vector< int >
#define pll pair< ll , ll >
#define pi pair< int , int >
#define all(s) s.begin() , s.end()
#define sz(s) s.size()
#define md (s + e) / 2
#define mid (l + r) / 2
#define msdp(dp) memset(dp , -1 , sizeof dp)
#define mscl(dp) memset(dp , 0 , sizeof dp)
using namespace std;
typedef long long ll;
ll q, k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
double dp[305][305][305];
double mem(ll a , ll b , ll c){
	//cout << a << " " << b << " " << c << endl;
	if(a < 0 || b < 0 || c < 0 || (!a && !b && !c))return 0.0;
	double &r = dp[a][b][c];
	if(r != -1.0)return r;
	r = 0.0;
	r = n * 1.0 / (a + b + c) * 1.0;
	if(a)r += (a * 1.0 / (a + b + c)* 1.0) * mem(a - 1 , b , c);
	if(b)r += (b * 1.0 / (a + b + c)* 1.0) * mem(a + 1, b - 1, c);
	if(c)r += (c * 1.0 / (a + b + c)* 1.0) * mem(a , b + 1, c - 1);
	//cout << r << " ";
	return r;  
}
void solve(){
	for(ll i = 0; i <= 300 ; i++)for(ll j = 0 ; j <= 300 ; j++)for(ll ii = 0 ; ii <= 300 ; ii++)dp[i][j][ii] = -1.0;
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		cin >> k;
		if(k == 1)o++;
		else if(k == 2)p++;
		else l++;
	}
	cout << fixed << setprecision(11) << mem(o , p , l);
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}

