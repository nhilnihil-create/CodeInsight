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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(N == 4){
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if(N == 5){
        cout << "2 5 20 30 63" << endl;
        return 0;
    }

    VI c;
    FOR(i,1,30001){
        int mo = i % 6;
        if(mo == 0 || mo == 2 || mo == 3 || mo == 4){
            c.eb(i);
        }
    }
    // 2,5,3,5,2,
    VI ans;
    LL sum = 0;
    REP(i,N){
        ans.eb(c[i]);
        sum += c[i];
    }
    if(sum%6 == 0){
        for(auto a : ans){
            cout << a << " ";
        }
        cout << endl;
        return 0;
    }else if(sum%6 == 2){
        ans.erase(ans.begin());
        ans.eb((ans.back() / 6 + 1) * 6);
    }else if(sum %6 == 3){
        ans.erase(ans.begin()+1);
        ans.eb((ans.back() / 6 + 1) * 6);
    }else if(sum %6 == 5){
        int t1 = ans.back() + 1;
        int t2 = ans.back() + 2;
        if(t1 % 6 == 4) ans.eb(t1);
        else ans.eb(t2);

        ans.erase(ans.begin()+1);

    }
    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;


}
