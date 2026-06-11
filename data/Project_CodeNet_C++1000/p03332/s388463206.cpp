#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long int ksm(long long int x,int b){
	long long int res = 1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}

long long int fac[300001];
long long int C(int n,int k){
	return fac[n]*ksm(fac[k],mod-2)%mod*ksm(fac[n-k],mod-2)%mod;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fac[0]=fac[1]=1;
	for(int i=2;i<=300000;i++)
		fac[i]=fac[i-1]*i%mod;
	int n,a,b;
	cin>>n>>a>>b;
	long long int k;
	cin>>k;
	long long int res = 0;
	for(int i=0;i<=n;i++){
		int j;
		long long int z = k-i*a;
		if(z%b==0&&z/b<=n&&z/b>=0)
			j=z/b;
		else
			continue;
		res = (res + C(n,i)*C(n,j))%mod;
	}
	cout<<res<<endl;
}
