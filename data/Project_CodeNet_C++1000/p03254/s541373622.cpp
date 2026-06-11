#include<bits/stdc++.h>
using namespace std;

const int N = 105;
typedef long long LL;

int n, x, a[N], ans;

int main() {
	cin>>n>>x;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++) {
		if(x < a[i]) {
			cout<<i - 1<<endl;
			return 0;
		}
		x -= a[i];
	}
	if(x == a[n]) cout<<n<<endl;
	else cout<<n - 1<<endl;
	return 0;
}