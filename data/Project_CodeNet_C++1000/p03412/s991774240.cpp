#include <cassert>
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
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
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
#include <string>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
vector <long long> A;
vector <long long> B;
int N;
int M = 30;
int main(void) {
	long long ans = 0;
	long long T = 1;
	cin >> N;
	rep(i, N) { 
		long long p;
		cin >> p;
		A.push_back(p);
	}
	rep(i, N) { 
		long long p;
		cin >> p;
		B.push_back(p);
	}
	rep(k, M) {
		vector <long long> C;
		vector <long long> D;
		rep(i, N) { 
			C.push_back(B[i] % (2 * T));
			D.push_back(A[i] % (2 * T));
		}
		sort(C.begin(),C.end());
		long long tmp = 0;
		rep(i, N) {
			tmp += lower_bound(C.begin(), C.end(), 2 * T - D[i]) - C.begin();
			tmp -= lower_bound(C.begin(), C.end(), 1 * T - D[i]) - C.begin();
			tmp += lower_bound(C.begin(), C.end(), 4 * T - D[i]) - C.begin();
			tmp -= lower_bound(C.begin(), C.end(), 3 * T - D[i]) - C.begin();
		}
		ans += T * (tmp % 2);
		T = T * 2;
	}
	cout << ans << endl;
	return 0;
}
