#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 505;
int a[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m, q;
	cin>>n>>m>>q;
	memset(a, 0, sizeof(a));
	for(int i = 0; i < m; i++){
		int l, r;
		cin>>l>>r;
		a[l][r]++;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 1, j = len; j <= n; i++, j++){
			a[i][j] += a[i + 1][j] + a[i][j - 1] - a[i + 1][j - 1];
		}
	}
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<a[l][r]<<'\n';
	}

	return 0;
}