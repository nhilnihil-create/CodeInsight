#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

template <typename T> inline void voutput(T &v){
    rep(i, v.size()){
        if (i) cout << " " << v[i];
        else cout << v[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    string s;
    cin >> s;
    vector<int> dp(1 << 26, inf);
    vector<int> C(s.size() + 1);
    C[0] = 0;
    rep(i, s.size()){
        C[i + 1] = C[i] ^ (1 << (s[i] - 'a'));
    }
    dp[0] = 0;
    rep(i, 1, s.size() + 1){
        int tmp = dp[C[i]] + 1;
        rep(j, 26){
            int c = C[i] ^ (1 << j);
            tmp = min(tmp, dp[c] + 1);
        }
        if(i == s.size()) output(tmp);
        dp[C[i]] = min(dp[C[i]], tmp);
    }
    
    return 0;
}
