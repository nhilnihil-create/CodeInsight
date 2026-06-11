#include<bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define mod 1e9
int32_t main() {
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	if(k&1)
		cout<<b-a;
	else cout<<a-b;
}
						