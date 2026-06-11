#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll dp[22][(1<<22)];
ll ans(vector<vector<int>> &compatible, int m, int women, int n){
    if(m==n){
        if(women==0)
            return 1;
        return 0;
    }
    if(dp[m][women] != -1)
        return dp[m][women];
        
    ll ret = 0;
    for(int i=0; i<n; i++){
        int available = ( (women) & (1<<i) ) == 0 ? 0 : 1;
        available = available && compatible[m][i];
        if(available){
            int newwomen =  (women) ^ (1<<i);
            ret =  (ret%M + ans(compatible, m+1, newwomen, n)%M )%M;
        }
    }
    
    return dp[m][women] = ret;
}
int main() {
	int n;
	cin>>n;
	
	vector<vector<int>> compatible(n, vector<int>(n, 0));
	for(int i=0; i<n; i++)
	    for(int j=0; j<n; j++)
	        cin>>compatible[i][j];
	memset(dp, -1, sizeof(dp));
	int women = ( (1<<n)-1 );
	//cout<<women;
	cout<<ans(compatible, 0, women, n);
	return 0;
}