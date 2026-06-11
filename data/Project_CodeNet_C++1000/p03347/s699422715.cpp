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

#define FOR(i, s, e) for(i = s; i < e; ++i)
#define FOR_INV(i, s, e) for(i = e - 1; i >= s; --i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;

LONG i, j, k;

int main(){
    LONG N;
    cin >> N;

    LONG A;
    LONG prev_A = -1;
    LONG count = 0;

    FOR(i, 0, N){
        cin >> A;

        if(count == -1){
            continue;
        }

        if(A > prev_A + 1){
            count = -1;
        }
        else if(A == prev_A + 1){
            ++count;
        }
        else{
            count += A;
        }

        prev_A = A;
    }

    count = max<LONG>(count - 1, -1);
    cout << count;
}

