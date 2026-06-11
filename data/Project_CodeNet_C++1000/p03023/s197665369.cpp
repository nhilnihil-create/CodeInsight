#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int BIG = 1e9;
const int maxN = 100 * 1000 + 9;
const string FILENAME = "sample";

int n;

void read(){
	cin >> n;
}

void solv(){
	cout << (n - 2) * 180 << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
#ifdef h4h4
	freopen((FILENAME + ".inp").c_str(), "r", stdin);
	freopen((FILENAME + ".out").c_str(), "w", stdout);
#endif

	read();
	solv();

	return 0;
}