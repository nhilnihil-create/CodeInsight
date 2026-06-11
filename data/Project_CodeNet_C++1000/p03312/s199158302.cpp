#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll N, A[200000];
ll sum[200001];

ll get_left(int a, int b) {
	ll ans;
	ans = max(sum[b] - sum[a], sum[a] - sum[0])
		- min(sum[b] - sum[a], sum[a] - sum[0]);
	return ans;
}

ll get_right(int b, int c) {
	ll ans;
	ans = max(sum[c] - sum[b], sum[N] - sum[c])
		- min(sum[c] - sum[b], sum[N] - sum[c]);
	return ans;
}

ll get_ans(int a, int b, int c) {
	//Aについて　[0,a - 1] [a, b - 1] [b, c - 1] [c, N - 1]　の区間での差を求める
	ll ans;
	ans = max(max(sum[a] - sum[0], sum[b] - sum[a]), max(sum[c] - sum[b], sum[N] - sum[c]))
		- min(min(sum[a] - sum[0], sum[b] - sum[a]), min(sum[c] - sum[b], sum[N] - sum[c]));	

	return ans;
}

int main() {
	cin >> N;
	sum[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
	}

	ll ans = 1e18;
	int left = 0, right = 2;

	for (int center = 1; center < N - 1; center++) {
		//左から一つ目のしきりのしゃくとり
		ll left_dif = get_left(left, center);
		while (1) {
			if (left_dif > get_left(left + 1, center)) {
				left++;
				left_dif = get_left(left, center);
			}
			else {
				break;
			}
		}

		//左から三つ目のしきりのしゃくとり
		ll right_dif = get_right(center, right);
		while (1) {
			if (right == N - 1)break;
			if (right_dif > get_right(center, right + 1)) {
				right++;
				right_dif = get_right(center, right);
			}
			else {
				break;
			}
		}
		ans = min(ans, get_ans(left, center, right));

	}

	cout << ans << endl;

	return 0;
}