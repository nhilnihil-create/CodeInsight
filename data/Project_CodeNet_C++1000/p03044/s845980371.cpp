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
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = pow(10,15);
ll k,x,m, n, h,r,c; string s;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
} 
ll d[100100]; vector<bool>  visit(100010,0);
vector<vector<pair<int,int>>> G;int an[100010];
void dfs(int s) {
    if (visit[s]) return;
    visit[s] = 1; pair<int, int> p;
    for (pair<int, int> i : G[s]) {
        p = i;
        if (p.second % 2 == 0) {
            an[p.first] = an[s];
        }
        else {
            an[p.first] = (an[s] + 1) % 2;
        }
        dfs(p.first);
    }
}
int main() {
    cin >> n; G.resize(n); int u, v, w;
    rep(i, n - 1) {
        cin >> u >> v >> w; u--; v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }an[0] = 0;
    dfs(0); 
    rep(i, n) cout << an[i] << endl;
}