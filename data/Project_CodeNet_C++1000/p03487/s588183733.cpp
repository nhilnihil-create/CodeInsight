#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;

	map<int, int> mp;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}

	int count = 0;
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		if (iter->first < iter->second) {
			count += iter->second - iter->first;
		}
		else if(iter->second < iter->first){
			count += iter->second;
		}
	}

	cout << count << endl;
	return 0;
}