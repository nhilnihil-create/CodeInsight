#include<bits/stdc++.h>
using namespace std;

const int N = 605;
typedef long long ll;

char a[N][N];
bool f[N][N][N];
int ans, n;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) {
			cin>>a[i][j];
			a[i + n][j + n] = a[i + n][j] = a[i][j + n] = a[i][j];
			f[i][j][0] = f[i + n][j + n][0] = f[i + n][j][0] = f[i][j + n][0] = 1;
		}
	for(int k = 1; k < n; k++)
		for(int i = 1; i <= 2*n && i + k <= 2*n; i++)
			for(int j = 1; j <= 2*n && j + k <= 2*n; j++) 
				if(a[i][j + k] == a[i + k][j]) f[i][j][k] = f[i][j][k - 1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			bool ok = 1;
			for(int k = 0; k < n; k++)
				if(!f[i + k][j + k][n - k - 1]) {
					ok = 0;
					break;
				}
			if(ok) ans++;
		}
	cout<<ans<<endl;
	return 0;
}