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
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int ans = 0;
    for(int ia=0;ia<=a;ia++) {
        for(int ib=0;ib<=b;ib++) {
            for(int ic=0;ic<=c;ic++) {
                if(500*ia+100*ib+50*ic==x) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
