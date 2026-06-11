#include <bits/stdc++.h>
using namespace std;
//frog1
int solve(vector<int> ar, int n){
    vector<int> dp(n+1);
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        int option1 = abs(ar[i]-ar[i-1]) + dp[i-1];
        int option2 = (i==2) ? INT_MAX : abs(ar[i]-ar[i-2]) + dp[i-2];
        dp[i] = min(option1, option2);
    }
    return dp[n];
}
int main() {
	int n;
	cin>>n;
	vector<int> ar(n+1);
	for(int i=1;i<=n;i++){
	    cin>>ar[i];
	}
	cout<<solve(ar, n);
	
	return 0;
}
