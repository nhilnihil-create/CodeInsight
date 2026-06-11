#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
using namespace std;
typedef long long ll;
//max=({});


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int train = min(a, b);
	int bus = min(c, d);
	int ans = train + bus;
	cout << ans << endl;
	return 0;
}
