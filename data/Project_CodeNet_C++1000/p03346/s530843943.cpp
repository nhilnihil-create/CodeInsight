#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

#define FOR(i, s, e) for(long i = s; i < e; ++i)

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


int main(){
    LONG N;
    cin >> N;

    vector<bool> passed(N + 1, false);
    vector<bool> valid(N, false);
    LONG P;

    passed[0] = true;

    FOR(i, 0, N){
        cin >> P;

        if(passed[P-1]){
            valid[P-1] = true;
        }

        passed[P] = true;
    }

    LONG longest = 0;
    LONG count = 1;

    FOR(i, 1, N){
        if(valid[i]){
            ++count;
        }
        else{
            if(count > longest){
                longest = count;
            }
            count = 1;
        }
    }

    longest = max(longest, count);

    cout << N - longest;

}
