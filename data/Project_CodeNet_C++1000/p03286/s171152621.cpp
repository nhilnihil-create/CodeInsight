#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    long long int n;
    cin >> n;
    if (n == 0) {
    	cout << 0 << endl;
    	return 0;
    }
    string res;
    long long int base = 1;
    while (n != 0) {
    	if (n / base % 2 != 0) {
    		res.push_back('1');
    		n -= base;
    	} else {
    		res.push_back('0');
    	}
    	base *= -2;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}
