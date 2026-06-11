#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
        int k=i;
		int cnt = 0;
		while (k > 0) {
			cnt += k % 10;
			k /= 10;
		}
		if (cnt >= a && cnt <= b) ans+=i;
	}
	cout << ans << endl;
}
