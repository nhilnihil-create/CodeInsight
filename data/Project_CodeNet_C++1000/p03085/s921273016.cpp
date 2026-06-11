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
	map<char, char> e{ { 'A', 'T' }, { 'T', 'A' }, { 'C', 'G' }, { 'G', 'C' } };

	char b;
	
	cin >> b;

	cout << e[b] << endl;


	return 0;
}
