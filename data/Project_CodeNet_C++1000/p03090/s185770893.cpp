#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool f[110][110];

int main(){
	ll n;
	cin>>n;
	cout<<n*(n-1)/2-n/2<<endl;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		f[i][i]=1;
		ll x=n;
		if(n%2==0)x++;
		if(i+j==x)f[i][j]=f[j][i]=1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(!f[i][j])cout<<i<<' '<<j<<endl;
		f[i][j]=f[j][i]=1;
	}
	return 0;
}
