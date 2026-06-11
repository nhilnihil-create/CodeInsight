#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <unordered_set>
#include <unordered_map>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x) 
#endif

typedef complex<double> point;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(it != v.begin())
            os << ",";
        os << *it;
    }
    return os << "}";
}

using ll = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a+b == 15) {
        cout << "+" << endl;
    } else if(a*b == 15) {
        cout << "*" << endl;
    } else {
        cout << "x" << endl;
    }
    return 0;
}
