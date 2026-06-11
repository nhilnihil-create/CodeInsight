#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
template <class T>
using lim = numeric_limits<T>;
 
bool can[10];
int cost[10] = {0,2,5,5,4,5,6,3,7,6};

string mymax(string a, string b){
	if (a.length() == b.length()) {
		if (a < b) return b;
		else return a;
	}
	else if (a.length() < b.length()) return b;
	else return a;
}
	
int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	memset(can, 0, sizeof can);
	
	int n, m;
	cin >> n >> m;
	
	string dp[n+1];
	for (int i = 0; i <= n; i++) dp[i]="0";
	dp[0] = "";
	for (int i = 0; i < m; i++){
		int a; cin >> a;
		can[a] = true;
	}
	
	// adding all available matches and getting the max
	// dp[i] is maximum val at i
	for (int i = 0; i < n; i++){
		for (int j = 1; j < 10; j++){
			if (!can[j] || dp[i]=="0" || i + cost[j] > n) continue;
			dp[i+cost[j]] = mymax(dp[i+cost[j]], dp[i]+(char)(j+'0'));
		}
	}
	
	cout << dp[n] << endl;
}
