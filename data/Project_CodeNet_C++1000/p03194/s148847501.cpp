# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;




int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long res = 1;
    for (long long i = 2; i * i <= m; ++i) if (m % i == 0) {
        int c = 0;
        while (m % i == 0) {
            m /= i;
            ++c;
        }
        c /= n;
        for (int j = 1; j <= c; ++j)
            res *= i;
    }
    if (n == 1) res *= m;
    cout << res << '\n';
    return 0;
    
}

