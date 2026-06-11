#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back

const int P = 1e9+7;

using namespace std;

int n;
string s;
ll dp[3030][3030];

int main(){

	cin >> n >> s;

	dp[0][0] = 1;
	int m = s.size();

	for(int i=0; i<m; i++){
		ll sum = 0;
		if(s[i] == '<'){
			for(int j=0; j<i+2; j++){
				dp[i+1][j] = sum;
				sum = (sum+dp[i][j])%P;
			}
		} else {
			for(int j=i; j>=0; j--){
				sum = (sum+dp[i][j])%P;
				dp[i+1][j] = sum;
			}
		}
	}

	ll ans = 0;

	for(int i=0; i<n; i++){
		ans = (ans+dp[m][i])%P;
	}

	cout << ans << endl;

	return 0;
}
