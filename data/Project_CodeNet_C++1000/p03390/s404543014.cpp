#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long q;
	cin>>q;
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long sqr=(long long)sqrt(x*y);
		if(x==y){
		    cout<<2*sqr-2<<endl;
		    continue;
	    }
		long long ans=2*sqr-1;
		if(sqr*(sqr+1)>=x*y) ans--;
		if(sqr*sqr==x*y) ans--;
		cout<<ans<<endl;
	}
	return 0;
} 