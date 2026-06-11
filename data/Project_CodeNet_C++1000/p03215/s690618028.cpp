#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll a[1010];
ll sum[1010];
ll bit[1010][50];
vector<ll> V;
int main()
{
	int N;
	ll K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + a[i];
	}
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			V.push_back(sum[i] - sum[j]);
		}
	}
	ll ans = 0;
	for (ll i = 50; i >= 0; i--) {
		ll sum = (1ll << i);
		vector<ll> nv;

		for (int j = 0; j < V.size(); j++) {
			if ((sum & V[j]) == (1ll << i)) {
				nv.push_back(V[j]);
			}
		}
		if (nv.size() >= K) {
			V = nv;
			ans += sum;
		}
	}
	cout << ans << endl;
}