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
    string c1, c2;
    cin >> c1 >> c2;

    if(c1.at(0)==c2.at(2)&&c1.at(1)==c2.at(1)&&c1.at(2)==c2.at(0)) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
