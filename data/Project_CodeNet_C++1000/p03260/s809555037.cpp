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
	int A = 0, B = 0, C = 0;

	cin >> A >> B;

	for (int i = 1; i <= 3; ++i){
		if ((A * B * i) % 2 == 1){
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}