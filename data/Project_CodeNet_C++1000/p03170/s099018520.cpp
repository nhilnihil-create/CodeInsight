#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	int n,k;
	cin>>n>>k;

	vector<bool> dp(k+1,0);
	vector<int> a(n);

	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	} 

	for(i=1;i<=k;++i){
		for(int x: a){
			if(x<=i && !dp[i-x]) dp[i]=1;
		}
	}
	printf("%s\n",dp[k] ? "First" : "Second");

return 0;
}