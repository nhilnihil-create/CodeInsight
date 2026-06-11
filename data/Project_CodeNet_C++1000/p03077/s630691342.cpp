#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
 
int main(){
	
	ll n,a,b,c,d,e;
	cin>>n>>a>>b>>c>>d>>e;
	ll now{},start{};
	b = min(a,b);
	c = min(b,c);
	d = min(d,c);
	e = min(e,d);
	now += (n+a-1)/a;
	
	cout << 4+(n+e-1)/e<<endl;
}
