#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m,c;
	cin>>n>>m>>c;

	int b[m];
	for(int i=0; i<m; i++) cin>>b[i];

	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	int ans = 0;

	for(int i=0; i<n; i++) {
		int val = 0;
		for(int j=0; j<m; j++) {
			val += a[i][j] * b[j];
		}

		ans += (val+c) > 0;
	}

	cout<<ans<<endl;
	
	return 0;
}