#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

int MOD_BIG = 1000000007;
int MOD_BIG2 = 998244353;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////

//////////////////////////////////////

int main() {
    
    int N, M;
    cin >> N >> M;
    using P = std::pair<int, int>;
    using PP = std::pair<ll, P>;
    vector<int> PRE(M);
    std::priority_queue<PP, vector<PP>, std::greater<PP>> pq;
    FOR(i, 0, M) {
        int p;
        ll q;
        cin >> p >> q;
        PRE[i] = p;
        pq.push(std::make_pair(q,std::make_pair(i, p)));
    }
    vector<int> num(N, 0);
    vector<int> ans(M);
    while (!pq.empty()) {
        auto pp = pq.top();
        pq.pop();
        ans[pp.second.first] = ++num[pp.second.second-1];
    }
    REP(i, M) {
        printf("%06d%06d\n", PRE[i], ans[i]);
    }
    
    return 0;
}
