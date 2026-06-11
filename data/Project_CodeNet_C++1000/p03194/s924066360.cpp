#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

// 素因数分解
// facotr[i].first  : 基数
// factor[i].second : 指数
void integerFactorization(long long n, vector<pair<long long, int> >& factor)
{
    factor.clear();
    long long a = 2;
    while(a * a <= n){
        int b = 0;
        while(n % a == 0){
            ++ b;
            n /= a;
        }
        if(b > 0)
            factor.push_back(make_pair(a, b));
        ++ a;
    }
    if(n > 1)
        factor.push_back(make_pair(n, 1));
}

int main()
{
    long long n, p;
    cin >> n >> p;

    vector<pair<long long, int> > factor;
    integerFactorization(p, factor);

    long long ans = 1;
    for(const auto& f : factor){
        long long i = f.second / n;
        while(--i >= 0)
            ans *= f.first;
    }
    cout << ans << endl;

    return 0;
}
