#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

int memo[2][2001][2001][2] = {};

int dfs(VI &a, VI &b, int &n, int x, int y, int t, bool bo=true) {
    if (memo[t][x][y][bo] > -1) return memo[t][x][y][bo];
    if (x == n || y == n) return memo[t][x][y][bo] = abs(a[x] - b[y]);
    if (t == 0) {
        if (!bo) return memo[t][x][y][bo] = dfs(a,b,n,max(x,y)+1,y,0);
        return memo[t][x][y][bo] = max(dfs(a,b,n,max(x,y)+1,y,0), dfs(a,b,n,x,max(x,y)+1,1));
    } else {
        if (!bo) return memo[t][x][y][bo] = dfs(a,b,n,max(x,y)+1,y,1);
        return memo[t][x][y][bo] = min(dfs(a,b,n,max(x,y)+1,y,0), dfs(a,b,n,x,max(x,y)+1,1));
    }
}

void solve() {
    int n,z,w;
    cin >> n >> z >> w;
    VI a(n+1), b(n+1);
    int in;
    a[0] = z; b[0] = w;
    REP(i,0,n) {
        cin >> in;
        a[i+1] = b[i+1] = in;
    }
    REP(i,0,2) REP(j,0,n+1) REP(k,0,n+1) REP(l,0,2) memo[i][j][k][l] = -1;
    cout << dfs(a,b,n,0,0,0,false) << endl;
}

int main() {
    solve();
    
    return 0;
}
