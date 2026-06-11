#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

int N;
int A[200000];
ll sum[200001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
	}

	ll ans = 1145141919810;
	for (int center = 2; center <= N - 2; center++) {
		//centerとcenter-1の間で真ん中の仕切りを入れる
		
		int leftpos;
		auto leftpos1 = lower_bound(sum, sum + center, (sum[center] - sum[0]) / 2);
		auto leftpos2 = leftpos1 - 1;
		ll a = abs(*leftpos1 - (sum[center] - sum[static_cast<int>(leftpos1 - sum)]));
		ll b = abs(*leftpos2 - (sum[center] - sum[static_cast<int>(leftpos2 - sum)]));
		if (a > b)leftpos = leftpos2 - sum;
		else leftpos = leftpos1 - sum;
		
		int rightpos;
		auto rightpos1 = lower_bound(sum + center + 1, sum + N + 1, (sum[N] + sum[center]) / 2);
		auto rightpos2 = rightpos1 - 1;
		a = abs((*rightpos1 - sum[center]) - (sum[N] - *rightpos1));
		b = abs((*rightpos2 - sum[center]) - (sum[N] - *rightpos2));
		if (a > b)rightpos = rightpos2 - sum;
		else rightpos = rightpos1 - sum;

		ll tmp = 0;

		tmp = max(max(sum[leftpos], sum[center] - sum[leftpos]),
			max(sum[N] - sum[rightpos], sum[rightpos] - sum[center])) -
			min(min(sum[leftpos], sum[center] - sum[leftpos]),
				min(sum[N] - sum[rightpos], sum[rightpos] - sum[center]));

		ans = min(ans, tmp);

	}
	
	cout << ans << endl;

	return 0;
}