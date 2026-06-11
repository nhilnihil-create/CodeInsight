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

int main()
{
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int P = max(X, max(Y, Z));
	int Q = min(X, min(Y, Z));

	cout << P - Q << endl;
}