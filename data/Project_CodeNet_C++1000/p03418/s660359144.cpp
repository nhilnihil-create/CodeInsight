#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int n,k; cin >> n >> k;
    	int ans = 0;
    	if(k == 0){
    		cout << n*n;
    		return 0;
    	}
    	for(int i = k+1; i <= n; i++)
    	{
    		int x = i - k;
    		int z = n/i;
    		ans += z*x + max(0LL,n%i-k+1);
    		//cout << ans << endl;
    	}
    	cout << ans;
    }    
}