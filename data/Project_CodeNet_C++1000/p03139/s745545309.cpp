#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	cout << min(a, b) << " " << endl;
	if (a + b <= n) cout << 0 << endl;
	else cout << a + b - n << endl;
	return 0;
}