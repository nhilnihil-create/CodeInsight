#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a,b;
	cin>>a>>b;
	int ans=0;
	if((a%4+44)%4!=0) {
		while((a%4+44)%4!=0) {
			ans^=a;
			a++;
			//cout<<a<<" "<<ans<<endl;
		}
	}
	if((b%4+44)%4!=3) {
		while((b%4+44)%4!=3) {
			ans^=b;
			b--;
			//cout<<b<<" "<<ans<<endl;
		}
	}
	cout<<ans;
}