#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100002

int n;

vector<long long int> v;

long long int way[MAX];

long long int ppow(long long int i,long long int j){
	long long int res=1;
	while(j){
		if(j&1LL)res*=i;
		if(res>=MOD)res%=MOD;
		j>>=1LL;
		i*=i;
		if(i>=MOD)i%=MOD;
	}
	return res;
}
long long int rng(int l,int r){
	if(l>r)return 0;
	long long int ret=way[r];
	if(l)ret+=MOD-way[l-1];
	ret%=MOD;
	return ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	long long int ans2=1;
	for(int i=1;i<=n;i++){
		ans2*=i;
		ans2%=MOD;
	}
	for(int i=1;i<=v.size();i++){
		way[i]=ans2*ppow(i,MOD-2);
		if(way[i]>=MOD)way[i]%=MOD;
		if(i)way[i]+=way[i-1];
		if(way[i]>=MOD)way[i]%=MOD;
	}
	long long int A=0;
	for(int i=0;i<n;i++){
		long long int ans=rng(1,i+1)+rng(2,n-i);
		if(ans>=MOD)ans%=MOD;
		A+=ans*v[i];
		if(A>=MOD)A%=MOD;
	}
	printf("%lld\n",A);
	return 0;
}
