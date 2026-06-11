#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define fi first
#define se second

int n,a[100005];

signed main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int dif = LONG_MAX, res = 1;
	for(int i = 1 ; i < n ; i ++)
		if(dif > abs(a[n] - 2*a[i]))
			dif = abs(a[n] - 2*a[i]), res = i;
	cout << a[n] << " " << a[res];
}
