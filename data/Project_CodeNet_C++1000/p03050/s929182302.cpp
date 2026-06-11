#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;


int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> divnum;
    for(int64_t i=1; i*i <= N; ++i) {
        if(N % i == 0) {
            divnum.push_back(i);
            if( N / i != i) {
                divnum.push_back(N/i);
            }
        }
    }
    int64_t sum = 0;
    for(auto r : divnum) {
        int64_t x = (N/r) - 1;
        if( x > r)
            sum += x;
    }

    cout << sum << endl;

    return 0;
}

