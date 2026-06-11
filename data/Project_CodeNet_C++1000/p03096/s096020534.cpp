#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
ll dp[200100];
ll last[200100];

int main(){
	int n; cin >> n;
	vector<int> c(n);
	dp[0]=1;
	for(int i=0;i<n;i++){
		cin >> c[i];
		if(last[c[i]]&&last[c[i]]<i){
			(dp[i+1]+=dp[last[c[i]]])%=mod;
		}
		(dp[i+1]+=dp[i])%=mod;
		last[c[i]]=i+1;
	}
	cout << dp[n]%mod << endl;
}