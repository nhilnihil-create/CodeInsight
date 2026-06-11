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

#define MOD_BIG 1000000007
#define MOD_BIG2 998244353
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
    
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    int root = 0, num = 0;
    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if (g[a].size() > num) {
            num = (int)g[a].size();
            root = a;
        }
        if (g[b].size() > num) {
            num = (int)g[b].size();
            root = b;
        }
    }
    std::priority_queue<ll> C;
    FOR(i, 0, N) {
        ll c;
        cin >> c;
        C.push(c);
    }
    vector<ll> ans(N);
    ll val = 0;
    std::queue<int> q;
    q.push(root);
    ans[root] = C.top();
    C.pop();
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for(auto e: g[v]) {
            if (ans[e] == 0) {
                ans[e] = C.top();
                val += C.top();
                C.pop();
                q.push(e);
            }
        }
    }
    
    cout << val << endl;
    for(auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}
