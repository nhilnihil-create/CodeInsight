#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int k;
	cin >> k;
	int ma = max(max(a, b), c);
	int co = ma;
	for (int i = 1; i <= k; i++) {
		ma *= 2;
	}
	cout << a + b + c - co + ma << endl;
	return 0;
}
