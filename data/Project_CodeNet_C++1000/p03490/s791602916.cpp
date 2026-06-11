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

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S; cin >> S;
    int x,y; cin >> x >> y;

    int acc = 0;
    VI move;
    REP(i,S.length())
    {
        if(S[i] == 'F') acc++;
        else{
            move.eb(acc);
            acc = 0;
        }
    }
    move.eb(acc);
    VI xmove,ymove;

    int cnt = 0;
    for(auto p : move)
    {
        if(cnt % 2 == 0) xmove.eb(p);
        else ymove.eb(p);

        cnt++;
    }
    VI dpx(20000,0);
    VI dpy(20000,0);
    // init: 10000, 100000

    if(S[0] == 'F'){
        dpx[10000+xmove[0]] = 1;
        dpy[10000] = 1;
    }
    else{
        dpx[10000] = 1;
        dpy[10000] = 1;
    }

    xmove.erase(xmove.begin());

    //cout << printVector(xmove) << endl;
    //cout << printVector(ymove) << endl;


    for(auto p : xmove)
    {
        VI truelist;
        REP(i,20000){
            if(dpx[i] == 1){
                truelist.eb(i+p);
                truelist.eb(i-p);
            }
        }
        dpx.assign(20000, 0);
        for(auto p : truelist){
            dump(p)
            dpx[p] = 1;
        }
    }

    dump("ymove")
    for(auto p : ymove)
    {
        VI truelist;
        REP(i,20000){
            if(dpy[i] == 1){
                truelist.eb(i+p);
                truelist.eb(i-p);
            }
        }
        dpy.assign(20000, 0);
        for(auto p : truelist){

            dump(p)
            dpy[p] = 1;
        }
    }

    if(dpx[10000+x] == 1 && dpy[10000+y] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;


}