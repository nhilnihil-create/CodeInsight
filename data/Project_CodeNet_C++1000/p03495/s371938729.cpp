#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int K, N;
	cin >> N >> K;
	map<int, int> mp;

	int types = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (mp[a] == 0) ++types;
		mp[a]++;
	}
	vector<int> vec;
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		vec.push_back(iter->second);
	}

	sort(vec.begin(), vec.end());

	int count = 0;
	int i = 0;
	for (; K < types; --types) {
		count += vec[i];
		++i;
	}


	cout << count << endl;
	return 0;
}