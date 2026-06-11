#include<bits/stdc++.h>
using namespace std;
int cntA,cntB,cntAB;
char s[15];
signed main(){
	long long ans=0,n,m,L,R;
	cin>>n;
	for(int i=1;1ll*i*i<=n;++i)
		if(n%i==0){
			long long m=i-1;
			if(m && (n/m)*(m+1)==n) ans+=m;
			if(1ll*i*i!=n){
				m=(n/i)-1;
				if(m && (n/m)*(m+1)==n) ans+=m;
			}
		}
	cout<<ans;
	return 0;
}