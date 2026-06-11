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

    vector<int> a1(n);
    vector<int> a2(n);
    int s1=0, s2=0;

    for(int in=0;in<n;in++) {
        cin >> a1.at(in);
        s1 += a1.at(in);
    }
    for(int in=0;in<n;in++) {
        cin >> a2.at(in);
    }
    s2 = a2.at(n-1);

    int ans = s1+s2;
    for(int in=n-1;in>=1;in--) {
        s1 -= a1.at(in);
        s2 += a2.at(in-1);
        ans = max(ans, s1+s2);
    }

    cout << ans << endl;
    return 0;
}
