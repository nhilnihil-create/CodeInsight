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
	string S;

	cin >> S;

	string s2 = S.substr(8, 2);

	cout << "2018/01/" + s2 << endl;

	return 0;
}
