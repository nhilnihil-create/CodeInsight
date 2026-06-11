//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

vector<pair<long long, long long>> FACT(long long n) {
    vector<pair<long long, long long>> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long cnt = 0;
            while (n % i == 0) cnt++, n /= i;
            res.push_back(make_pair(i, cnt));
        }
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main() {

    long long N, P;
    cin >> N >> P;

    auto res = FACT(P);
    long long ans = 1;

    for (auto x : res) {
        if (x.second >= N) {
            long long d = x.second / N;
            for (int i = 0; i < d; i++) ans *= x.first;
        }
    }


    cout << ans << endl;

}

























