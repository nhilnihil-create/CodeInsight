#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 105;
int n, f[N][10], p[N][11], res = INT_MIN;

void solve() {
    cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<10; j++)
			cin >> f[i][j];
	for(int i=0; i<n; i++)
		for(int j=0; j<=10; j++)
			cin >> p[i][j];
	for(int i=1; i< 1<<10; i++) {
		int a=0;
		for (int j=0; j<n; j++) {
			int b=0;
			for (int k=0; k<10; k++)
				b += bool(i & 1<<k) && f[j][k];
			a += p[j][b];
		}
		res = max(res, a);
	}
	cout<<res<<endl;
}
 
int main() {
    solve();
    return 0;
}
