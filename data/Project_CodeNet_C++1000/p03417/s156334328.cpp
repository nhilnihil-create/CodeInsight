#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>

#define repAll(n) (n).begin(), (n).end()
#define repConAll(n) (n).cbegin(), (n).cend()

using namespace std;

namespace {

}

int main()
{
	long long N = 0, M = 0;

	cin >> N >> M;

	// 外側1周分のみ表。

	long long sum = 0;
	
	if (N == 1 && M == 1){
		sum = 1;
	}
	else if (N == 1){
		sum = M - 2;
	}
	else if (M == 1){
		sum = N - 2;
	}
	else {
		sum = (N - 2) * (M - 2);
	}

	cout << sum;

	return 0;
}