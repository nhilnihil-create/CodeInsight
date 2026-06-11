#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 500005;
const int mod = 1e9 + 7;
#define sz(v) ((int)v.size())

int n, a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a + n);
	pi dap(-2e9, -1);
	for(int i=0; i<n-1; i++){
		int cst = min(a[n-1] - a[i], a[i]);
		dap = max(dap, pi(cst, i));
	}
	cout << a[n-1] << " " << a[dap.second] << endl;
}
