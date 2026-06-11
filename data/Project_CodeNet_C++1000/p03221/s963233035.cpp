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
typedef pair<long long,long long> P;
//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}
long long nCr(long long n, long long r) {
    long long A = 1, B = 1;
    //Aが分子Bが1/r!
    for (long long i = n - r + 1; i <= n; i++) {
        A = A * i % MOD;
    }
    for (long long i = 1; i <= r; i++) {
        B = B * i % MOD;
    }
    B = mod_pow(B, MOD - 2);
    B %= MOD;
    //Bは割るのではなく掛ける
    return (A * B) % MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
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
        long long hantei = ok(key,mid);
        if(hantei) right = mid;
        else left = mid;
    }
    if(left == -1)return 0;
    return left;
}

int main() {
    int N,M;cin >> N >> M;
    vector<tuple<int,int,long long>> retu;
    for(int i = 0;i<M;i++){
        int a,b;cin >> a >> b;
        int c = i;
        retu.push_back(make_tuple(a,b,c));
    }
    sort(retu.begin(),retu.end());
    vector<string> ans(M);

    int hinan = get<0>(retu.at(0));
    int num = 0;

    for(int i = 0;i<M;i++){
        int city = get<0>(retu.at(i));
        //int num = 1;
        int index = get<2>(retu.at(i));
        if(hinan != city) {
            num = 1;
            hinan = city;
        }
        else num++;
        string S,T;
        if(city < 10){
            S = "00000" + to_string(city);
        }
        else if(city < 100){
            S = "0000" + to_string(city);
        }
        else if(city < 1000){
            S = "000" + to_string(city);
        }
        else if(city < 10000){
            S = "00" + to_string(city);
        }
        else if(city < 100000){
            S = "0" + to_string(city);
        }
        else S = to_string(city);

        if(num < 10){
            T = "00000" + to_string(num);
        }
        else if(num < 100){
            T = "0000" + to_string(num);
        }
        else if(num < 1000){
            T = "000" + to_string(num);
        }
        else if(num < 10000){
            T = "00" + to_string(num);
        }
        else if(num < 100000){
            T = "0" + to_string(num);
        }
        else T = to_string(num);

        ans.at(index) = S+T;
    }    

    for(int i = 0;i<M;i++){
        cout << ans.at(i) << endl;
    }


    // PLEASE GIVE ME THE "ACCEPTED" !
}
