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
#include <unordered_set> //unordered_set
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
    int D,G;cin >> D >> G;
    //first:問題番号,second:問題数,third:コンプボーナス
    vector<tuple<int,int,int>> problems(D);
    for(int i = 1;i<=D;i++){
        int index,num,comp;cin >> num >> comp;
        index = i;
        problems.at(i-1) = make_tuple(index,num,comp);
    }
    //sort(problems.begin(),problems.end());
    //点数高い問題から取れるようにする
    reverse(problems.begin(),problems.end());
    int ans = 11451419;
    for(int bit = 0;bit < (1 << D);bit++){
        bitset<12> B(bit);
        int now = 0;
        int solved = 0;
        for(int i = 0;i<D;i++){
            //ビットが立っていたらコンプする
            if(B.test(i)){
                now += (D-i)*100*(get<1>(problems.at(i)));
                now += get<2>(problems.at(i));
                solved += get<1>(problems.at(i));
            }
        }
        if(now >= G){
            ans = min(ans,solved);
            continue;
        }
        //コンプだけじゃ足りなかったら、点数高い問題をコンプしないように取る
        //と思ったけど明らかにコンプまで取った方が得
        for(int i = 0;i<D;i++){
            if(!B.test(i)){
                int num = get<1>(problems.at(i));
                for(int j = 0;j<num;j++){
                    if(now >= G){
                        ans = min(ans,solved);
                        continue;
                    }
                    now += (D-i)*100;
                    solved++;
                }
            }
        }
    }

    cout << ans << endl;

}