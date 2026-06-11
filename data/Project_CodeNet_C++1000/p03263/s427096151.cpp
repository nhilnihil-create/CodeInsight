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
    int H,W;cin >> H >> W;
    vector<vector<int>> retu(H,vector<int>(W));
    for(int i = 0;i<H;i++)for(int j = 0;j<W;j++) cin >> retu.at(i).at(j);
    vector<tuple<int,int,int,int>> ans;
    for(int i = 0;i<H;i++){
        if(i % 2 == 0){
            for(int j = 0;j<W-1;j++){
                if(retu.at(i).at(j) % 2 == 1){
                    retu.at(i).at(j+1)++;
                    ans.push_back(make_tuple(i,j,i,j+1));
                }
            }
            if(retu.at(i).at(W-1) % 2 == 1){
                if(i != H-1){
                    retu.at(i+1).at(W-1)++;
                    ans.push_back(make_tuple(i,W-1,i+1,W-1));
                }
            }
        }
        else{
            for(int j = W-1;j>=1;j--){
                if(retu.at(i).at(j) % 2 == 1){
                    retu.at(i).at(j-1)++;
                    ans.push_back(make_tuple(i,j,i,j-1));
                }
            }
            if(retu.at(i).at(0) % 2 == 1){
                if(i != H-1){
                    retu.at(i+1).at(0)++;
                    ans.push_back(make_tuple(i,0,i+1,0));
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i<ans.size();i++){
        cout << get<0>(ans.at(i))+1 << " "  << get<1>(ans.at(i))+1 << " " << get<2>(ans.at(i))+1 << " " << get<3>(ans.at(i))+1 << endl; 
    }
}
