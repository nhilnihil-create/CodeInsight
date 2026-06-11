#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> comp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>comp[i][j];
        }
    }
    vector<int> dp(1<<n,0);
    dp[0]=1;
    for(int mask=0;mask<dp.size();mask++){
        int m=__builtin_popcount(mask);
        for(int w=0;w<n;w++){
            if(!(mask&(1<<w))&&comp[m][w]){
                dp[mask|(1<<w)]+=dp[mask];
                dp[mask|(1<<w)]%=1000000007;
            }
        }
    }
    cout<<dp.back();
	return 0;
}