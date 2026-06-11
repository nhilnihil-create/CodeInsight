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
	vector<int> vec(3);
	cin >> vec[0] >> vec[1] >> vec[2];

	sort(vec.begin(), vec.end());

	int count = 0;
	while (vec[0] != vec[2] && vec[0] != vec[2] - 1) {
		vec[0] += 2;
		++count;
	}
	while (vec[1] != vec[2] && vec[1] != vec[2] - 1) {
		vec[1] += 2;
		++count;
	}

	sort(vec.begin(), vec.end());
	if (vec[0] == vec[1] && vec[1] == vec[2]) {
		//pass
	}
	else if (vec[0] == vec[1]) {
		++count;
	}
	else if (vec[1] == vec[2]) {
		count += 2;
	}

	cout << count << endl;
	return 0;
}