#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];

	vector<vector<ll> > dp(n,vector<ll> (n,LLONG_MAX));
	vector<vector<ll> > s(n,vector<ll> (n,LLONG_MAX));
	for(int i=0;i<n;i++){
		dp[i][i]=0;
		s[i][i]=0;
	}

	for(int j=1;j<n;j++){
		for(int i=j-1;i>=0;i--){
			for(int k=i;k<j;k++){
				ll tmp=dp[i][k]+dp[k+1][j];
				if(k==i)
					tmp+=v[i];
				if(k+1==j)
					tmp+=v[j];
				ll t=tmp+s[i][k]+s[k+1][j];

				if(t<s[i][j]){
					dp[i][j]=tmp;
					s[i][j]=t;
				}
			}
		}
	}
	
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		if(i<=j)
	// 			cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<s[0][n-1]<<endl;

	return 0;
}