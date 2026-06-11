#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	int pos = -1;
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		if(x == 1)pos = i;
	}
	int ans = n;
	for(int i = pos - k + 1; i <= pos; i++){
		if(i < 0 || i + k - 1 > n)continue;
		int tmp = 1 + (i + k - 3)/(k - 1) + (n - i - 1)/(k - 1);
		// cout<<i<<" "<<tmp<<endl;
		ans = min(ans, tmp);
	}
	cout<<ans<<endl;

	return 0;
}