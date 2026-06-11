#include <bits/stdc++.h>

#define REP(i, n) for(decltype(n) i = 0; i < n; i++)

#define ALL(c)   c.begin(), c.end()
#define SORT(c)  std::sort(ALL(c))
#define RSORT(c) std::sort(ALL(c), std::greater<decltype(c)::value_type>())

using namespace std;
using ll = long long;

const int MOD  = (int)1e9 + 7;
const int INF  = (int)1e9 + 1;
const ll  LINF = (long long)1e18 + 1;

class UnionFind {
public:
    struct Node {
        long long parent, rank, weight;
        Node() = default;
        Node(const long long& _parent,
             const long long& _rank,
             const long long& _weight = 0) :
            parent(_parent),
            rank(_rank),
            weight(_weight) { }
    };

    std::vector<Node> node;

    UnionFind(const long long& num_node) :
        node(num_node) {
        for(long long i = 0; i < num_node; i++) {
            node[i].parent = i;
        }
    }

    long long searchAndZipRoot(const long long& x) {
        if(node[x].parent == x) {
            return x;
        }
        else {
            auto r = searchAndZipRoot(node[x].parent);
            node[x].weight += node[node[x].parent].weight;
            return node[x].parent = r;
        }
    }

    long long calcWeight(const long long& x) {
        searchAndZipRoot(x);
        return node[x].weight;
    }

    void unite(const long long& x,
               const long long& y,
               const long long& weight = 0) {
        auto rx = searchAndZipRoot(x);
        auto ry = searchAndZipRoot(y);
        if(rx != ry) {
            auto yw = weight + calcWeight(x) - calcWeight(y);
            if(node[rx].rank < node[ry].rank) {
                std::swap(rx, ry);
                yw *= -1;
            }
            node[ry].parent = rx;
            node[ry].weight = yw;
            if(node[rx].rank == node[ry].rank) {
                node[rx].rank++;
            }
        }
    }

    long long calcDiff(const long long& x,
                       const long long& y) {
        return std::abs(calcWeight(x) - calcWeight(y));
    }

    template<class... A>
    bool checkWhetherRootIsSame(const A&... nodes) {
        auto node_list = std::initializer_list<long long>{nodes...};
        if(node_list.size() < 2) return false;
        auto v = searchAndZipRoot(*node_list.begin());
        for(size_t i = 1; i < node_list.size(); i++) {
            if(v != searchAndZipRoot(*(node_list.begin() + i))) return false;
        }
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    UnionFind tree(N);

    string ans = "Yes";
    REP(i, M) {
        int l, r, d;
        std::cin >> l >> r >> d;
        l--; r--;

        if(!tree.checkWhetherRootIsSame(l, r)) {
            tree.unite(r, l, d);
        }
        else {
            if(tree.calcDiff(l, r) != d) {
                ans = "No";
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
