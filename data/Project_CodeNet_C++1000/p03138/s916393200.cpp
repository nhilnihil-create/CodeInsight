#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> pi;
int maxn = 40;
long long unit = 1;
long long bits_on[45];
long long bits_off[45];
long long dp[50];
vector<long long>xbit;
long long f(int b){
	if(b<0) return 0;
	long long &ret = dp[b];
	if(~ret) return ret;
	ret = 0;
	long long absolute = unit<<b;
	ret = bits_on[b]*absolute+f(b-1);
	ret = max(ret,bits_off[b]*absolute+f(b-1));
	return ret;
}
int main(){
	int n;
	memset(dp,-1,sizeof(dp));
	long long k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		long long a;
		cin>>a;
		for(int i=0; i<=maxn; i++){
			if((unit<<i)&a) bits_on[i]++;
			else bits_off[i]++;
		}
	}
	while(k){
		xbit.push_back(k%2);
		k/=2;
	}
	long long psum = 0;
	long long ret = 0;
	int l = maxn-xbit.size();
	for(int i=0; i<l; i++) xbit.push_back(0);
	for(int i=xbit.size()-1; i>=0; i--){
		if(xbit[i]){
			long long temp = psum;
			temp+=bits_on[i]*(unit<<i);
			temp+=f(i-1);
			ret = max(ret,temp);
			psum+=bits_off[i]*(unit<<i);
		}
		else{
			psum+=bits_on[i]*(unit<<i);
		}
	}
	ret = max(ret,psum);
	cout<<ret;
}