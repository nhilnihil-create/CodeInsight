#include <bits/stdc++.h>
using namespace std;

#define INIT std::cin.tie(0);std::ios::sync_with_stdio(false);
#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define FOR(i, s, n) for (int i = s; i < static_cast<int>(n); i++)
#define ASC(t) [](t& x, t& y){ return x < y; }
#define DESC(t) [](t& x, t& y){ return x > y; }
#define PSORT(s,p,e) partial_sort((s), next((s), (p)), (e))
#define VIEW(v,t) for_each((v).begin(), (v).end(), [](t& a) { cout << a << " "; }); cout << endl;

#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T& x, const T y){return x=(x<y)?y:x;}
template<class T> inline T CHMIN(T& x, const T y){return x=(x>y)?y:x;}
#define OUT(dist) std::cout<<(dist);
#define WS std::cout<<" ";
#define NL std::cout<<"\n"

using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using LL = long long;
using ULL = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T, int W=255> using A = array<T, W>;
template<class T, int W=255, int H=255> using A2 = array<array<T, W>, W>;

int N;
V<V<int>> e;

V<bool> vis1;
V<bool> vis2;

int dfs() {
    vis1.resize(N+1,true);
    vis2.resize(N+1,true);

    std::stack<tuple<int,int>> stk1;
    stk1.push(make_tuple(1,0));
    int u = 1, maxd1 = 0, s, d;
    while(!stk1.empty()) {
        std::tie(s,d) = stk1.top();
        stk1.pop();
        REP(i,e[s].size()) if(vis1[e[s][i]]) {
            stk1.push(make_tuple(e[s][i],d+1));
            vis1[e[s][i]] = false;
            if(maxd1 < d+1) u = e[s][i], maxd1 = d+1;
        }
    }

    std::stack<tuple<int,int>> stk2;
    stk2.push(make_tuple(u,0));
    int v = u, maxd2 = 0;
    while(!stk2.empty()) {
        std::tie(s,d) = stk2.top();
        stk2.pop();
        if(e[s].size() > 0) {
            REP(i,e[s].size()) if(vis2[e[s][i]]) {
                stk2.push(make_tuple(e[s][i],d+1));
                vis2[e[s][i]] = false;
                if(maxd2 < d+1) v = e[s][i], maxd2 = d+1;
            }
        }
    }

    return maxd2;
}

int main(){
    INIT;
    cin >> N;
    e.resize(N+1);
    REP(i,N-1) {
        int x,y; cin >> x; cin >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int dm = dfs();
    cout << (dm%3 != 1 ? "First" : "Second") << "\n";
}