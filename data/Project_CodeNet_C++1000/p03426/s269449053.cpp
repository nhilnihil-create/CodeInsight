// clang-format off
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <map>
using namespace std;
#define DEB(variable) cout << #variable << '=' << variable << endl

#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr long long int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

// clang-format on
struct Point {
    int y, x;
};
int kyori(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {

    int h, w, d;
    cin >> h >> w >> d;

    vector< Point> mp(h*w+1);
    int tmp;
    REP(i, h) {
        REP(j, w) {
            scanf("%d", &tmp);
            mp[tmp] = {(int)i, (int)j};
        }
    }
    vector<vector<int>> grid(d, vector<int>((h * w + 3 * d - 1) / d, 0ll));
    FOR(i,1,h*w+1) {
        grid[i % d][i / d] = kyori(mp[i], mp[i + d]);

        if(i == h * w - d) {
            break;
        }
    }
    mp.clear();
    vector<vector<int>> sum(d, vector<int>((h * w + 4 * d - 1) / d, 0ll));
    REP(i, d) {
        REP(j, (h * w + 2 * d - 1) / d) {
            sum[i][j + 1] = sum[i][j] + grid[i][j];
        }  
    }
    grid.clear();
    int q;
    cin >> q;
    int a, b;
    REP(i,q){
        scanf("%d %d", &a,&b);
        printf("%d\n", sum[b % d][b / d] - sum[a % d][a / d] );
    //    cout << "unko" << endl;
    }
    return 0;
}
