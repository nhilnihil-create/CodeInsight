/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#define WOULD
#define YOU
#define PLEASE
#define ACCEPT
#define MY
#define SUBMISSION
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
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
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100;
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
    return a * b / gcd(a, b);
}

int main() {
    int A,B,C;cin >> A >> B >> C;
    int maxi = max({A,B,C});
    int X = 0,Y = 0;
    if(A == maxi){
        X = maxi-B;
        Y = maxi-C; 
    }
    if(B == maxi){
        X = maxi-A;
        Y = maxi-C; 
    }
    if(C == maxi){
        X = maxi-A;
        Y = maxi-B; 
    }
    int count = 0;
    while(true){
        if(X >= 1 && Y >= 1){
            X-=1;
            Y-=1;
            count++;
            continue;
        }
        if(X >= 2){
            X-=2;
            count++;
        }
        if(Y >= 2){
            Y-=2;
            count++;
        }
        if(X == 1 && Y == 0){
            count+=2;
            break;
        }
        if(X == 0 && Y == 1){
            count+=2;
            break;
        }
        if(X == 0 && Y == 0) break;
    }
    cout << count << endl;
}