#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;
	vi v(n),dp(k+1,0);
	F(i,0,n){
		cin>>v[i];
		// dp[v[i]]=1;
	}
	F(i,1,k+1){
		F(j,0,n){
			if(i-v[j]>=0)
				dp[i]=dp[i]|!dp[i-v[j]];
		}
	}
	cout<<(dp[k]?"First":"Second");
	return 0;
}