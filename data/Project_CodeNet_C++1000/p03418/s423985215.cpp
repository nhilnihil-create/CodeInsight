
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main()
{
	int n, k;
	cin >> n >> k;

	ll cnt = 0;
	for (int b = k+1; b <= n; b++) {
		
		cnt += 1LL*(b - k) * (n / b);
		cnt += max(n % b - (k-1), 0);
		if (k == 0) {
			cnt--;
		}
	}
	cout << cnt << endl;
}  

