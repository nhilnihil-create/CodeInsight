#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	long long ans=0;

	for(long long i=1;i<=n;i+=2){
		long long cnt=0;
		for(long long j=1;j<=i;j++){
			if(i%j==0) cnt++;
		}
		if(cnt==8) ans++;
	}

	cout<<ans<<endl;

	return 0;
}
