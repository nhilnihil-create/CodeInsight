#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
vector<int> prime_factor(int num) {
    vector<int>res;
    for (int i = 2; i <= num; i++) { // 他の素数で割っていく
        while (num % i == 0) {
			res.push_back(i);
            num /= i;
        }
    }
    return res;
}
int cnt[345678];
signed main() {
	int n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int h = 0; h < prime_factor(i).size(); h++) {
			cnt[prime_factor(i)[h]]++;
			//cout << i << ' ' << prime_factor(i)[h] << endl;
		}
	}
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (int h = 2; h <= n; h++) {
		if (cnt[h] >= 74)ans++;
		if (cnt[h] >= 24)a++;
		if (cnt[h] >= 2)b++;
		if (cnt[h] >= 14)c++;
		if (cnt[h] >= 4)d++;
	}
	ans += a * (b - 1) + c * (d - 1) + (d * (d - 1) / 2) * (b - 2);
	cout << ans << endl;
	return 0;
}