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
	string n;
	cin >> n;
	for (auto s : n) {
		if (s == '1') 
			cout << '9';
		else
			cout << '1';
	}
	cout << endl;
}
