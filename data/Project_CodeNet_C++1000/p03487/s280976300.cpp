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

    map<int, int> mp;
    
    int a;
    for(int in=0;in<n;in++) {
        cin >> a;
        auto result = mp.insert(make_pair(a, 1));
        if(!result.second) mp[a]++;
    }

    int ans = 0;
    for(auto imp:mp) {
        if(imp.first<=imp.second) ans += imp.second - imp.first;
        else ans += imp.second;
    }
    cout << ans << endl;
    return 0;
}
