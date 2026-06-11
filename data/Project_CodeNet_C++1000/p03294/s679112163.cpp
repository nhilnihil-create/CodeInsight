#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N];
	rep(i,N) cin >> a[i];
	int ans = 0;
	rep(i,N) ans += a[i]-1;
	cout << ans << endl;
	
	return 0;
}
