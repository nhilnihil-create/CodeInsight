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

class Data
{
public:
    int w, s;
    long long v;
    bool operator< (const Data& d) const{
        return d.s - w < s - d.w;
    }
};

const long long INF = LLONG_MAX / 2;

int main()
{
    int n;
    cin >> n;
    vector<Data> d(n);
    for(int i=0; i<n; ++i)
        cin >> d[i].w >> d[i].s >> d[i].v;
    sort(d.begin(), d.end());

    vector<long long> dp(10001, -INF);
    for(int i=0; i<n; ++i){
        for(int a=1; a<=10000; ++a){
            int b = min(d[i].s, a - d[i].w);
            if(b >= 0)
                dp[b] = max(dp[b], dp[a] + d[i].v);
        }
        dp[d[i].s] = max(dp[d[i].s], d[i].v);
    }

    long long ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;

    return 0;
}
