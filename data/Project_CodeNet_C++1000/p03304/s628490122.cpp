#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(_i, s, e) for(_i = s; _i < e; ++_i)
#define FOR_INV(_i, s, e) for(_i = e - 1; _i >= s; --_i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;


int main(){
    LONG i, j, k;
    LONG n, m, d;

    cin >> n >> m >> d;

    double ret;
    if(d == 0){
        ret = n;
    }
    else{
        ret = 2 * (n - d);
    }
    ret *= m - 1;
    ret /= n * n;

    cout << fixed << setprecision(7) << ret;
}
