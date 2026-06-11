#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(c, b/a) << "\n";
	return 0;
}