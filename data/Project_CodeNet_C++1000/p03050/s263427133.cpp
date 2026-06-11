#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	long long ans=0;//(m+1)x=N
	set<long long> yakusu;

	for(long long i=1;i*i<=n;i++){
		if(n%i==0){
			yakusu.insert(i);
			yakusu.insert(n/i);
		}
	}

	for(auto at=yakusu.begin();at!=yakusu.end();at++){
		long long m=*at-1;

		if(m>0 && n/m==n%m) ans+=m;
	}

	cout<<ans<<endl;

	return 0;
}
