#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

struct Node {
public:
    vector<int> to;
};

int main() {
    int N; cin >> N;
    vector<set<int>> vs(N);
    vector<int> rank(N);
    vector<vi> edges(N - 1);
    vector<Node> vec(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        rank[a]++; vec[a].to.push_back(b);
        rank[b]++; vec[b].to.push_back(a);
        edges[i] = { a,b };
    }
    vector<int> c(N); rep(i, N) cin >> c[i];
    sort(ALL(c));

    for (int r = 0; r < N; r++) {
        int rk = rank[r];
        vs[rk].insert(r);
    }
    int ind = 0;
    vector<int> ans(N);

    while (!vs[1].empty()) {
        int u = *vs[1].begin();
        ans[u] = c[ind];
        ind++;
        // cとそれにadjacentなNodeのrankを一つずつ下げて回る
        vs[1].erase(u);
        rank[u] = 0;
        for (int i = 0; i < vec[u].to.size(); i++) {
            int v = vec[u].to[i];
            vs[rank[v]].erase(v);
            if (rank[v] > 0) {
                rank[v]--;
                vs[rank[v]].insert(v);
            }
        }
    }
    while (!vs[0].empty()) {
        int u = *vs[0].begin();
        ans[u] = c[ind];
        ind++;
        // cとそれにadjacentなNodeのrankを一つずつ下げて回る
        vs[0].erase(vs[0].begin());
    }
    ll score = 0;
    for (auto e : edges) {
        score += min(ans[e[0]], ans[e[1]]);
    }
    cout << score << endl;
    for (auto& a : ans) {
        cout << a << " ";
    }
    cout << endl;
}