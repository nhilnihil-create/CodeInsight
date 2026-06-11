#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int fac[100001];
long long int ksm(long long int x,int b){
	long long int res = 1;
	while(b){
		if(b&1)	res = res * x %mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	fac[0]=1;
	long long int ans = 0, tot = 0;
	for(int i=1;i<=n;i++)
		fac[i] = fac[i-1]*i%mod;
	for(int i=1;i<=n;i++)
		tot = (tot + fac[n]*ksm(i,mod-2))%mod;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		ans = (ans+tot*x)%mod;
		tot = (tot + fac[n]*ksm(i+1,mod-2)-fac[n]*ksm(n+1-i,mod-2))%mod;
	}
	cout << (ans%mod+mod)%mod<<endl;
}
