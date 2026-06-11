#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
*/

// 実装が大変でした

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll>a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	// すべて均等になるようにしたい
	// どうやるんだろう

	// まず半分に分ける？
	// 半分に分ける位置を全探索する
	ll leftSum = 0;
	ll rightSum = 0;
	int index;

	ll leftleftSum = 0;
	ll leftrightSum;
	int leftIndex = 0;

	ll rightleftSum = 0;
	ll rightrightSum;
	int rightIndex = 0;

	ll ans = infll;

	rep(i, n) {
		leftSum += a[i];
		rightSum = sum - leftSum;
		if (i == 0) continue;
		if (i >= n - 2) continue;

		// i番目とi+1番目で区切る
		index = i;

		// 尺取り法を使って計算量を大幅カット

		// 左側で区切る
		Rep(j, leftIndex, index + 1) {
			leftleftSum += a[j];
			leftrightSum = leftSum - leftleftSum;
			if (leftrightSum < leftleftSum) {
				if (abs(leftleftSum - leftrightSum) < abs(leftrightSum - leftleftSum + 2 * a[j])) {
					leftIndex = j;
				}
				else {
					leftleftSum -= a[j];
					leftrightSum += a[j];
					leftIndex = j - 1;
				}
				break;
			}
		}
		leftIndex++;
		if (index == 1) rightIndex = index + 1;
		else rightleftSum -= a[index];
		// 右側で区切る
		Rep(j, rightIndex, n) {
			rightleftSum += a[j];
			rightrightSum = rightSum - rightleftSum;

			if (rightrightSum < rightleftSum) {
				if (abs(rightleftSum - rightrightSum) < abs(rightrightSum - rightleftSum + 2 * a[j])) {
					rightIndex = j;
				}
				else {
					rightleftSum -= a[j];
					rightrightSum += a[j];
					rightIndex = j - 1;
				}
				break;
			}
		}
		rightIndex++;

		ll ma = max({ leftleftSum, leftrightSum, rightleftSum, rightrightSum });
		ll mi = min({ leftleftSum, leftrightSum, rightleftSum, rightrightSum });

		//cout << index + 1 << "番目と" << index + 2 << "番目の間で区切る" << endl;
		//cout << leftleftSum << " " << leftrightSum << " " << rightleftSum << " " << rightrightSum << endl;
		//cout << ma - mi << endl;
		ans = min(ans, ma - mi);
	}

	cout << ans << endl;

	return 0;
}
