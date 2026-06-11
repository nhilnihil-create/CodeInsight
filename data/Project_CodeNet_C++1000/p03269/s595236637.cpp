#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from;
    int to;
    int w;
};

int solve() {
    int L;
    cin >> L;
    vector<Edge> e;
    int m = 0;
    while ( L >> m ) m++;
    for ( int i = 0; i < m-1; i++ ) {
        e.push_back(Edge{i, i+1, 0});
    }
    for ( int i = 0; i < m-1; i++ ) {
        e.push_back(Edge{i, i+1, 1<<i});
    }
    for ( int i = m-1; i >= 1; i-- ) {
        if ( L & (1<<(i-1)) ) {
            int w = L & ~((1<<i)-1);
            e.push_back(Edge{i-1, m-1, w});
        }
    }
    cout << m << " " << e.size() << "\n";
    for ( auto ee : e ) {
        cout << ee.from + 1 << " " << ee.to + 1 << " " << ee.w << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}