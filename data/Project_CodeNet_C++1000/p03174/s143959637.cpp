#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}


int main(){

	int n;
	cin >> n;
	vector<vector<int>> x(n,vector<int>(n));
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j){
			cin>>x[i][j];
		}
	}
	vector<int> dp(1<<n);
	dp[0]=1;
	for (int mask=0; mask<(1<<n)-1;++mask){
		int p = __builtin_popcount(mask);
		for (int i=0;i<n;++i){
			if (x[p][i] && !(mask & (1<<i))){
				int m =mask^(1<<i);
				dp[m] = (dp[m]+dp[mask])%mod;
			}
	
	}

}
cout<<dp[(1<<n)-1]<<endl;
}