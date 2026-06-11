#include <cstdio>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef unsigned long long ll;

ll arr[200005];
int dec[200005];
double S[200005];
int pmin[200005];
int main(){
	int K; scanf("%d", &K);
	int k = 0;
	for (int i = 1;i < 10000;i++) arr[k++] = i;
	for (ll i = 4, p = 10;i <= 17;i++, p *= 10) {
		for (ll j = 1;j < 10000;j++) {
			arr[k++] = j * p + (p - 1);
		}
	}
	sort(arr, arr + k);
	k = unique(arr, arr + k) - arr;
	for (int i = 0;i < k;i++) {
		ll cur = arr[i];
		while (cur) {
			dec[i] += cur % 10;
			cur /= 10;
		}
		S[i] = 1.0*arr[i] / dec[i];
	}
	S[k] = 1e30;
	pmin[k] = k;
	for (int i = k - 1;i >= 0;i--) {
		if (S[pmin[i + 1]] < S[i]) pmin[i] = pmin[i + 1];
		else pmin[i] = i;
	}
	vector<ll> ans;
	for (int i = 0;i < k;i++) {
		if (arr[i]*dec[pmin[i+1]] <= arr[pmin[i + 1]]*dec[i]) ans.push_back(arr[i]);
	}
	for (int i = 0;i<K;i++) printf("%llu\n", ans[i]);
}