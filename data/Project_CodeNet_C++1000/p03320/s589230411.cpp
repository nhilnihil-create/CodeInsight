#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<numeric>
#include<vector>

using namespace std;
typedef long long ll;
typedef pair<ll, double> P;

int retketasum(ll K) {
	int ans = 0;
	while (K > 0) {
		ans += (K % 10);
		K /= 10;
	}
	return ans;
}

int main() {

	int K;
	cin >> K;
	set<ll> ans;
	vector<P> destination;
	
	for (int i = 0; i < 9; i++)ans.insert(i + 1), destination.push_back(P(i + 1, 1));
	
	//A=(p)999999 9を最後尾でn個含む
	for (int n = 13; n >= 1; n--){ 
		int limit_p = 1;
		for (; limit_p <= min(9 * n + (ll)(9 * (log10(limit_p) + 1)) - 1,
			(ll)(pow(10, 15 - n) - 1)); limit_p++);

		limit_p--;
		//nごとのpの限界値を調べた

		for (; limit_p >= 1; limit_p--) {
			double tmp = (double)(pow(10, n) - 1 + limit_p * pow(10, n)) /
				(double)(9.0 * n + retketasum(limit_p));
			if (destination.size() == 9) {
				ans.insert(pow(10, n) - 1 + pow(10, n) * limit_p);
				destination.push_back(P(pow(10, n) - 1 + pow(10, n) * limit_p, tmp));
				continue;
			}
			auto tmp_find = lower_bound(destination.begin(), destination.end(),
				P(pow(10, n) - 1 + pow(10, n) * limit_p, 0));

			if (tmp_find == destination.end())tmp_find = --destination.end();

			if ((*tmp_find).second >= tmp) {

				//cout << "number = " << pow(10, n) - 1 + pow(10, n) * limit_p << endl;
				//cout << "raito = " << tmp << endl;

				ans.insert(pow(10, n) - 1 + pow(10, n) * limit_p);
				destination.push_back(P(pow(10, n) - 1 + pow(10, n) * limit_p, tmp));
				sort(destination.begin(), destination.end());
			}
		}
	}
	auto itr = ans.begin();
	for (int i = 0; i < K; i++) {
		cout << *itr << endl;
		itr++;
	}
	return 0;
}