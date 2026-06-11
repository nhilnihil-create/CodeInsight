#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MAX_N = 2123456;

LL A[MAX_N] = {};
LL B[MAX_N] = {};
LL C[MAX_N] = {};

template<typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

LL solve(int k, string S){
    LL res = 0;
    int n = S.length();
    REP(i,n){
        if(S[i] == 'D'){
            res += B[i+k] - B[i] - C[i] * (A[i+k]-A[i]);
            dump(res)

        }
    }
    return res;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    VI k(Q); REP(i,Q) cin >> k[i];

    REP(i,N){
        if(S[i] == 'C') A[i+1] = A[i] + 1;
        else A[i+1] = A[i];
    }
    REP(i,N){
        if(S[i] == 'M') C[i+1] = C[i] + 1;
        else C[i+1] = C[i];
    }
    REP(i,N){
        if(S[i] == 'C'){
            B[i+1] = B[i] + C[i+1];
        }else{
            B[i+1] = B[i];
        }
    }

    FOR(i,N+1,MAX_N){
        B[i] = B[i-1];
        A[i] = A[i-1];
        C[i] = C[i-1];
    }


    //print_array(A,20);
    //print_array(B,20);
    //print_array(C,20);


    REP(i,Q){
        cout << solve(k[i], S) << endl;
    }

}
