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
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);

    sort(p.begin(), p.end(), greater<int>());

    cout << p.at(0)*10+p.at(1)+p.at(2) << endl;

    return 0;
}
