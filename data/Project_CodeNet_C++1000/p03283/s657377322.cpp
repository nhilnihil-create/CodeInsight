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
    LONG N, M, Q;
    cin >> N >> M >> Q;

    vector<LVEC> sum(N + 1, LVEC(N+1, 0));
    LONG L, R;
    LONG i, j;

    FOR(i, 0, M){
        cin >> L >> R;
        sum[L][R] += 1;
    }


    FOR(i, 0, N){
        FOR(j, 0, N){
            sum[i+1][j+1] = sum[i+1][j+1] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
//            cout << sum[i+1][j+1] << " ";
        }

//        cout << endl;
    }



    LVEC result(Q, 0);
    FOR(i, 0, Q){
        cin >> L >> R;
        result[i] = sum[R][R] - sum[L-1][R];
    }

    FOR(i, 0, Q){
        cout << result[i] << endl;
    }
}


