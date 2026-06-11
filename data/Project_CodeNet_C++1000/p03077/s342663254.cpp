#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
	ll a,b,c,d,e,n;
	cin>>n>>a>>b>>c>>d>>e;
	ll tightest = 1ll<<61;
	tightest = min(tightest, a);
	tightest = min(tightest, b);
	tightest = min(tightest, c);
	tightest = min(tightest, d);
	tightest = min(tightest, e);
	ll r = 5 + (n + tightest-1)/tightest - 1;
	cout<<r<<'\n';
	return 0;
}
