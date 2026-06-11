#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, c;
    cin >> n >> c;

    vector<vector<int>> d(c, vector<int>(c));
    for(int ic=0;ic<c;++ic) {
        for(int jc=0;jc<c;++jc) {
            cin >> d[ic][jc];
        }
    }
    int color;
    vector<vector<int>> grid(c, vector<int>(3, 0));
    for(int in=0;in<n;++in) {
        for(int jn=0;jn<n;++jn) {
            cin >> color; --color;
            ++grid[color][(in+jn+2)%3];
        }
    }

    int ans = 1e9, anstmp;
    for(int c1=0;c1<c;++c1) {
        for(int c2=0;c2<c;++c2) {
            for(int c3=0;c3<c;++c3) {
                if(c1==c2||c2==c3||c3==c1) continue;
                anstmp = 0;
                for(int ic=0;ic<c;++ic) {
                    if(ic!=c1) anstmp += grid[ic][0]*d[ic][c1];
                    if(ic!=c2) anstmp += grid[ic][1]*d[ic][c2];
                    if(ic!=c3) anstmp += grid[ic][2]*d[ic][c3];
                }
                chmin(ans, anstmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
