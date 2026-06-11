#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans=min(b,c);
	b-=ans; c-=ans;
	ans*=2;
	if (c>0) {
		if (a>=c) ans+=c;
		else ans+=a+1;
	}
	else ans+=b;
	cout<<ans<<endl;
	return 0;
} 