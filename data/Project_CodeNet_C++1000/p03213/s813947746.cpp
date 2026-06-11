#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int maxn = 105;
int era[105];
vector<int>primes;
int dp[105][105];
int counter[105];
void proccess(int n){
	while(n!=1){
		counter[era[n]]++;
		n/=era[n];
	}
}
int f(int curr,int make){
	if(curr>=primes.size()) return 0;
	int&ret = dp[curr][make];
	if(~ret) return ret;
	ret = 0;
	for(int i=0; i<=primes[curr]; i++){
		if(make%(i+1)==0){
			if(make==i+1) ret++;
			else ret+=f(curr+1,make/(i+1));
		}
	}
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	for(int i=2; i<=maxn; i++) era[i] = i;
	for(int i=2; i*i<=maxn; i++){
		if(era[i]==i){
			for(int j=i*i; j<=maxn; j+=i) era[j] = i;
		}
	}
	int n;
	cin>>n;
	for(int i=2; i<=n; i++){
		proccess(i);
	}
	for(int i=2; i<=n; i++){
		if(counter[i]) primes.push_back(counter[i]);
	}
	cout<<f(0,75);
}