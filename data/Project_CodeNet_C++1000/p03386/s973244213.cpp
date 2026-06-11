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
	// int N = 0;

	long long A, B, K;

	cin >> A >> B >> K;


	for (long long i = A; i <= B; ++i){
		if ((i <= A + K - 1) 
			|| (i >= B - K + 1)){
			cout << i << endl;
		}
	}
	


	return 0;
}