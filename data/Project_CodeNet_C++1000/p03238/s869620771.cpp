/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    WRITER:kakitamasziru/OxOmisosiru
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#define _GLIBCXX_DEBUG
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100100;
const int MOD = 1000000007;
typedef pair<int,int> P;
//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

int main() {
    int N;cin >> N;
    if(N == 1) {
        cout << "Hello World" << endl;
    }
    else{
        int a,b;cin >> a >> b;cout << a+b << endl;
    }

    // PLEASE GIVE ME THE "ACCEPTED" !
}