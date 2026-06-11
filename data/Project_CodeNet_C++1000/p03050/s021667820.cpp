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

int main()
{
	ll N;
	cin >> N;
	vector<ll> V;
	for (ll i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			if (i * i != N) V.push_back(i - 1);
			if (i * i != N) V.push_back(N / i - 1);
		}
	}
	ll ans = 0;
	for (ll num : V) {
		if (num == 0) continue;
		if (N / num == N % num) ans += num;
	}
	cout << ans << endl;
}
