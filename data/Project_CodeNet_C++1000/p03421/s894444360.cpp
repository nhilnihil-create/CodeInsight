#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main() {
	cin>>n>>a>>b;
	if (a+b-1>n||1ll*a*b<n) return cout<<-1,0;
	int d=n-a;
	for (int i=n-a+1;i<=n;++i) cout<<i<<' ';
	for (int i=2;i<=b;++i) {
		int t=min(d-(b-i),a);
		for (int j=d-t+1;j<=d;++j) cout<<j<<' ';
		d-=t;
	}
}