#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,ans,ml=1,mr=100000;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin >> l >> r;
		ml=max(ml,l);
		mr=min(mr,r);
	}
	ans = max(0,mr - ml + 1);
	cout << ans << endl;
	return 0;
}
