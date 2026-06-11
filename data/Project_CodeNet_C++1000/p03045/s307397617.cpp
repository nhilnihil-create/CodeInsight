#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1<<60);
int k, x, m, n, h, r, w,y,d; ll sum = 0,c; string s,t;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
vector<bool> visit(100010, 0);
vector<vector<int>> G;
void dfs(int s) {
    if (visit[s]) return;
    visit[s] = 1;
    for (int i : G[s]) dfs(i);
}
int main() {
    cin >> n >> m; G.resize(n);
    rep(i, m) {
        cin >> x >> y >> d; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    rep(i, n) {
        if (!visit[i]) {
            sum++;
            dfs(i);
        }
    }cout << sum << endl;
}