#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
static const int INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n, INF);
    int atmp, variety=0;
    for(int in=0;in<n;in++) {
        cin >> atmp; atmp--;
        if(a.at(atmp)==INF) { 
            a.at(atmp) = 1;
            variety++;
        }
        else a.at(atmp)++; 
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for(int in=0;in<variety-k;in++) {
        ans += a.at(in);
    }
    cout << ans << endl;
    return 0;
}
