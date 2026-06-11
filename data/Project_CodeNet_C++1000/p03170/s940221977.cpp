#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define maxn 100005

int main()
{
	ll n, k, temp;
	bool dp[maxn];
	cin >> n >> k;
	vector<ll> x;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		x.push_back(temp);
	}
	for (int i = 1; i <= k; ++i) {
		bool current = false;
		for (auto each : x) {
			if (i - each >= 0) {
				current = current || !dp[i - each];
			}
		}
		dp[i] = current;
	}
	string str = dp[k] ? "First" : "Second";
	cout << str << endl;
	return 0;
}
