#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }


int main(void) {
    string s;
    cin >> s;

    for(int i3=0;i3<3;i3++) {
        if(s.at(i3)=='1') cout << 9;
        else if(s.at(i3)=='9') cout << 1;
        else cout << s.at(i3);
    }

    return 0;
}
