
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
#include <iterator>
using namespace std;

namespace {

}

int main()
{
	int N;

	cin >> N;
	
	int sq = sqrt(N); // 切り捨て

	int sq2 = sq + 1;

	if (sq2 * sq2 <= N){
		cout << sq2 * sq2 << endl;
		return 0;
	}

	cout << sq * sq << endl;

	return 0;
}