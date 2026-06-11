#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

namespace {

}

int main()
{
	std::string s;

	int a = 0, b = 0, c = 0, d = 0;

	cin >> a >> b >> c >> d;

	if ((abs(c - a) <= d) || 
		(abs(b -a) <= d && abs(c -b) <=d)){
		cout << "Yes";
	}
	else {
		cout << "No";
	}


	return 0;
}
