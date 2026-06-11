#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = 0;
	rep(i, n - 1) {
		if (a[i] == a[i + 1]) {
			ans++;
			i++;
		}
	}
	cout << ans << endl;
}