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

//long long A,B;
bool ok(long long key,long long index){
    if(index > key) return true;
    else if(index <= key) return false;
}
long long binary_search(long long key,long long size){
    //left,right,midはいずれもindex
    long long left = -1,right = size;
    while(right - left > 1){
        long long mid = left + (right-left)/2;
        bool hantei = ok(key,mid);
        if(hantei) right = mid;
        else left = mid;
    }
    if(left == -1)return 0;
    return left;
}

//leftは条件を満たさない最大の値、rightは条件を満たす最小の値になっている

string query(int index){
    cout << index << endl;
    fflush(stdout);
    string result;cin >> result;
    if(result == "Vacant"){
        //main()に戻らずにプログラムを終了する
        exit(0);
    }
    else {
        return result;
    }
}

int main() {
    int N;cin >> N;
    string L = query(0);
    string R = query(N-1);
    int left = 0;
    int right = N-1;
    for(int i = 0;i<20;i++){
        int mid = left+(right-left)/2;
        string M = query(mid);
        //左の区間が偶数個かつ両端が同じ　または　左の区間が奇数個かつ両端が異なる
        //ならば左の区間に必ず空席が含まれるので左の区間に合わせる
        if((mid-left) % 2 == 1 && M == L || (mid-left) % 2 == 0 && M != L){
            right = mid;
            R = M;
        }
        else{
            left = mid;
            L = M;
        }
    }
}
