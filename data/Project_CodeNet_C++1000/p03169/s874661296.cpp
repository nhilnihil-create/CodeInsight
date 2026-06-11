#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1e9
#define MIN -1e9
#define MOD 1000000007
#define println(x) cout << "[" << #x << ":" << x << "]\n"; 
#define print(x) cout << "[" << #x << ":" << x << "] "; 

double dp[301][301][301];

double solve(int one, int two, int three, int &n){
	if(one < 0 || two < 0 || three < 0)
		return 0;
	if(one == 0 && two == 0 && three == 0)
		return 0;
	if(dp[one][two][three] > 0)
		return dp[one][two][three];
	int remaining_sushi = one + two + three;
	double exp_value = n + one*solve(one-1, two, three, n) + two*solve(one+1, two-1, three, n) + three*solve(one, two+1, three-1, n);
	return dp[one][two][three] = (double)exp_value/remaining_sushi;
}

int main(){
	ios::sync_with_stdio(0); 
    cin.tie(0); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n; cin >> n;
	int one = 0, two = 0, three = 0;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		if(x == 1)
			one++;
		else if(x == 2)
			two++;
		else
			three++;
	}

	memset(dp, -1, sizeof dp);
	cout << fixed << setprecision(10) << solve(one, two, three, n);
	return 0;
}