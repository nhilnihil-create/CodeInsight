#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

#define rep(i,N) for(int i=0;i<(int)N;++i)

#include <iostream>

int main()
{
	string S;
	cin >> S;

	string A = S.substr(0, 4);
	int a = stoi(A);
	string B = S.substr(5, 2);
	string C = S.substr(8, 2);

	if (a <= 2018) { cout << "Heisei" << endl; }
	else if (a == 2019) {
		if (B == "01" || B == "02" || B == "03" || B == "04") { cout << "Heisei" << endl; }
		else { cout << "TBD" << endl; }
	}
	else { cout << "TBD" << endl;}
}