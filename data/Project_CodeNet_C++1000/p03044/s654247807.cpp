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
const long long INF = 100100100100;
const long long MOD = 1000000007;
typedef pair<int,long long> P;

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

vector<vector<P>> Edge(100005);
vector<int> ans(100005,-1);
vector<long long> dist(100005);

int main() {
    int N;cin >> N;
    for(int i = 0;i<N-1;i++){
        int a,b,c;cin >> a >> b >> c;
        a--;b--;
        Edge.at(a).push_back(make_pair(b,c));
        Edge.at(b).push_back(make_pair(a,c));
    }
    //first:from second:dist
    queue<P> Q;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        P p = Q.front();Q.pop();
        int from = p.first;long long D = p.second;
        if(D % 2 == 0) ans.at(from) = 0;
        else ans.at(from) = 1;
        for(P V : Edge.at(from)){
            if(ans.at(V.first) != -1) continue;
            Q.push(make_pair(V.first,V.second+D));
        }
    }
    for(int i = 0;i<N;i++)cout << ans.at(i) << endl;
}
