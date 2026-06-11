#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n), dp(k+1);
    for (int i=0; i<n; ++i)
    	cin>>a[i];
    for (int i=1; i<=k; ++i){
    	for (auto& x: a){
    		if (i-x>=0 && !dp[i-x]){
    			dp[i]=1;
    			break;
    		}
    	}
    }
    cout<<(dp[k]?"First":"Second");
    return 0;
}