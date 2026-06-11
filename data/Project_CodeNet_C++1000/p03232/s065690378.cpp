#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int m[505050];
int factor(int num){
	int ans=1;
	for(int i=2;i<=num;i++)
		ans=(long long)ans*i%MOD;
	return ans;
}
int inv[505050];
void initinv(int num){
	inv[1]=1;
	for(int i=2;i<=num;i++)
		inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
}
unsigned s[505050];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;i++)
		cin>>m[i];
	initinv(N);
	for(int i=1;i<=N;i++)
		s[i]=(s[i-1]+inv[i])%MOD;
	unsigned ans=0;
	for(int i=1;i<=N;i++)
		ans=(ans+(long long)(s[N-i+1]+s[i]-1)*m[i])%MOD;
	ans=(long long)ans*factor(N)%MOD;
	printf("%u\n",ans);
	return 0;
}