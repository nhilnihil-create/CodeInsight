#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

string strmax( string a, string b ){
	if( a.l_ength() == b.l_ength() ) return ( a > b ) ? a : b;
	else return ( a.l_ength() > b.l_ength() ) ? a : b;
}

vector<string> dp(10100);
const int gs[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	int n, m; cin >> n >> m;
	vector<char> match(m);
	for( auto &k : match ) cin >> k;
	fill_n( dp.begin(), 10000, "" );
	for( int i = 0; i <= n; ++i ){
		for( char k : match ){
			if( !( i != 0 && dp[i] == "") ){
				dp[i+gs[k-'0']] = strmax( dp[i+gs[k-'0']], dp[i]+k );
			}
		}
	}
	cout << dp[n] << endl;
}