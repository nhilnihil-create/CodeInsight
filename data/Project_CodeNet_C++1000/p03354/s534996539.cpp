#include <bits/stdc++.h>
using namespace std;

using llong = long long;

// warrnig : The range of this class is from 0 to n-1
class UnionFindTree {
  public:
    //'rank[x]' is a rank of the union find tree the root of which is x.
    //'parents[x]' is the parent of x
    vector<int> rank, parents;

    // constructor
    UnionFindTree() {}
    UnionFindTree(int n) { // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeSet(i);
        }
    }

    // make a union find tree
    void makeSet(int x) {
        parents[x] = x; // the parent of x is x
        rank[x] = 0;
    }

    // check whether the root of x is the same as that of y
    bool same(int x, int y) { return findSet(x) == findSet(y); }

    // unite two tree
    void unite(int x, int y) { link(findSet(x), findSet(y)); }
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    // travel the parents of tree recursivily to find root
    int findSet(int x) {
        if (x != parents[x]) {
            parents[x] = findSet(parents[x]); // change the x's parent to the root of tree.
        }
        return parents[x];
    }
};

int main() {
    int N;            // the number of nodes
    int Q;            // the number of query
    vector<int> P;    // p is a "same" or "unite" command.
    vector<int> A, B; // a and b are nodes.

    cin >> N >> Q;
    UnionFindTree uft = UnionFindTree(N); // make trees

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p--;
        P.push_back(p);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
    }

    for (int i = 0; i < Q; i++) {
        uft.unite(A[i], B[i]);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (uft.same(i, P[i])) {
            sum++;
        }
    }
    cout << sum << endl;

    return 0;
}
