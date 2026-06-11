/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
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
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 10010010010010;
const long long MOD = 1000000007;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b ;
}

int main() {
    int N;cin >> N;
    long long ans = 0;
    long long miniminus = INF;
    vector<long long> retu(N);
    for(int i = 0;i<N;i++) cin >> retu.at(i);
    for(int i = 0;i<N-1;i++){
        if(retu.at(i) < 0){
            retu.at(i) *= -1;
            retu.at(i+1) *= -1;
        }
        miniminus = min(miniminus,abs(retu.at(i)));
        ans += retu.at(i);
    }
    if(retu.at(N-1) > 0){
        ans += retu.at(N-1);
        cout << ans << endl;
        return 0;
    }
    //終点を引く
    if(miniminus > abs(retu.at(N-1))){
        miniminus = min(miniminus,abs(retu.at(N-1)));
        ans -= miniminus;
    }
    else{
        //途中を引く（事前に足してあるので2回引く）
        ans += abs(retu.at(N-1));
        ans -= miniminus;
        ans -= miniminus;
    }
    cout << ans << endl;

}
