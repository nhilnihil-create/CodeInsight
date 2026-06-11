#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e3 + 3;

int dp[N], A[N];

signed main(){
	int n, a, b;
	cin >> n >> a >> b;
    
    memset(dp , 22, sizeof dp);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> A[i];
        int t = 0;
        int mx = 0;
        for(int j=i-1; j>=0; j--){
            if(A[j] > A[i]) t++;
        	else mx = max(mx , A[j]);
            if(mx == A[j])
                dp[i] = min(dp[i] , dp[j] + a*t + b*(i-j-1-t));
        }
    }
    
    int mx = 0;
    int ans = 1LL << 60;
    for(int i=n; i>=1; i--){
        if(mx < A[i]){
            mx = A[i];
            ans = min(ans , dp[i] + (n-i)*b);
        }
    }
    
    cout << ans;
    return 0;
}