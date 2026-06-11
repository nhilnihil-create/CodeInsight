#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

int MOD_BIG = 1000000007;
int MOD_BIG2 = 998244353;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////

//////////////////////////////////////

int main() {
    
    int K;
    cin >> K;
    vector<ll> A(K);
    REP(i, K) cin >> A[i];
    
    ll max = 2, min = 2;
    IREP(i, K) {
        ll test = ((min / A[i])) * A[i];
        if (test < min) test += A[i];
        min = test;
        test = ((max / A[i])) * A[i];
        if (test <= max) test += A[i];
        max = test - 1;
        //cerr << max << ", " << min << endl;
        if (max < min) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << min << " " << max << endl;
    
    return 0;
}
