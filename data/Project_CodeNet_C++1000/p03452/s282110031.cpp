#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)

class UnionFind
{
public:
    explicit UnionFind(int N)
    {
        m_par.reserve(N);
        for (int n = 0; n < N; ++n) {
            m_par.push_back(n);
        }
        m_dist = vll(N);
    }
    int Root(int n)
    {
        if (m_par[n] == n) return n;
        while (m_par[n] != m_par[m_par[n]]) {
            m_dist[n] += m_dist[m_par[n]];
            m_par[n] = m_par[m_par[n]];
        }
        return m_par[n];
    }
    bool Unite(int n, int m, ll d)
    {
        if (Root(n) == Root(m)) {
            if (m_dist[m] - m_dist[n] == d)  return true;
            else return false;
        }
        m_dist[Root(n)] = m_dist[m]-d;
        if (n != Root(n)) m_dist[Root(n)] += -m_dist[n];
        m_par[Root(n)] = Root(m);
        return true;
    }
    bool Same(int n, int m)
    {
        return Root(n) == Root(m);
    }
    vi m_par;
    vll m_dist;
};

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    UnionFind UF(N);
    for (int m = 0; m < M; ++m) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        --l; --r;
        if (!UF.Unite(l, r, d)) {
            cout << "No\n";
            return 0;
        }
    }
    for (int n = 0; n < N; ++n) {
        UF.Root(n);
        if (abs(UF.m_dist[n]) > 1e9) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
