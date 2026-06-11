#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n;
    cin >> n;

    vector<int> c(n-1);
    vector<int> s(n-1);
    vector<int> f(n-1);

    for(int in=0;in<n-1;in++) {
        cin >> c.at(in) >> s.at(in) >> f.at(in);
    }

    int ans;
    for(int in=0;in<n-1;in++) {
        ans = 0;
        for(int jn=in;jn<n-1;jn++) {
            ans = max(ans, s.at(jn));
            if((ans-s.at(jn))%f.at(jn)!=0) ans += f.at(jn) - (ans - s.at(jn))%f.at(jn);
            ans += c.at(jn);
        }
        cout << ans << endl;
    }
    cout << 0 << endl; 
    return 0;
}
