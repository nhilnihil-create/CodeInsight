#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

const int bound = 200010;
ll dp[bound];
int vorh[bound];

void init(){
	dp[0] = 1;
	for( int i = 0; i < bound; ++i ) vorh[i] = -1;
}

int main(){
	int n; cin >> n;
	vector<int> tmp(n);
	for( auto &k : tmp ) cin >> k;
	tmp.push_back(-1);
	vector<int> farbe;
	for( int i = 0; i < n; ++i ){
		if( tmp[i] != tmp[i+1] ){
			farbe.push_back(tmp[i]);
		}
	}
	n = farbe.size();
	init();
	for( int i = 0; i < n; ++i ){
		dp[i+1] = dp[i];
		if( vorh[farbe[i]] == -1 ){
			vorh[farbe[i]] = i;
		} else {
			dp[i+1] += dp[vorh[farbe[i]]];
			dp[i+1] %= mod;
			vorh[farbe[i]] = i+1;
		}
	}
	cout << dp[n] << endl;
}