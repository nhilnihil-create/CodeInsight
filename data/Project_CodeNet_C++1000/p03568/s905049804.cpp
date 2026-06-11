#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	int n,a[10],sum = 1,ans;
	cin >> n; ans = pow(3, n);
	rep(i, n) {
		cin >> a[i];
		if (a[i] % 2 == 0) sum *= 2;
	}
	cout << ans - sum << endl;
}