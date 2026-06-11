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

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

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

bool check(int L, int s, char a, char b, string S, string T){
    int N = S.length();
    int left = 1;
    int right = L;
    bool ok = 1;
    for(int i = N-1; i>=0; i--){
        if(i != N-1){ //青木くんのターン
            if(T[i] == a){
                right = min(L,right+1);
            }
            else if(T[i] == b){
                left = max(1,left-1);
            }
        }

        //高橋くんのターン
        if(S[i] == a){
            left = left + 1;
        }
        else if(S[i] == b){
            right = right - 1;
        }

        if(left > right) ok = 0;

    }

    if(s < left || right < s) ok = 0;

    return ok;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W,N; cin >> H >> W >> N;
    int sr,sc; cin >> sr >> sc;
    string S,T; cin >> S >> T;

    bool yoko = check(W,sc,'L','R',S,T);
    bool tate = check(H,sr,'U','D',S,T);

    if(yoko&&tate){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


}
