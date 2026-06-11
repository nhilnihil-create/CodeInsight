#include <bits/stdc++.h>
 
using namespace std;
 
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

vector<u64> par, dsu_2ecc, dsu_cc, dsu_cc_size;
u64 bridges;
u64 lca_iteration;
vector<u64> last_visit;

void init(u64 n) {
    par.resize(n);
    dsu_2ecc.resize(n);
    dsu_cc.resize(n);
    dsu_cc_size.resize(n);
    lca_iteration = 0;
    last_visit.assign(n, 0);
    for (u64 i=0; i<n; ++i) {
        dsu_2ecc[i] = i;
        dsu_cc[i] = i;
        dsu_cc_size[i] = 1;
        par[i] = -1;
    }
    bridges = 0;
}

u64 find_2ecc(u64 v) {
    if (v == -1)
        return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
}

u64 find_cc(u64 v) {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
}

void make_root(u64 v) {
    v = find_2ecc(v);
    u64 root = v;
    u64 child = -1;
    while (v != -1) {
        u64 p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v;
        v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_path (u64 a, u64 b) {
    ++lca_iteration;
    vector<u64> path_a, path_b;
    u64 lca = -1;
    while (lca == -1) {
        if (a != -1) {
            a = find_2ecc(a);
            path_a.push_back(a);
            if (last_visit[a] == lca_iteration){
                lca = a;
                break;
                }
            last_visit[a] = lca_iteration;
            a = par[a];
        }
        if (b != -1) {
            b = find_2ecc(b);
            path_b.push_back(b);
            if (last_visit[b] == lca_iteration){
                lca = b;
                break;
                }
            last_visit[b] = lca_iteration;
            b = par[b];
        }

    }

    for (u64 v : path_a) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
    for (u64 v : path_b) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
}

void add_edge(u64 a, u64 b) {
    a = find_2ecc(a);
    b = find_2ecc(b);
    if (a == b)
        return;

    u64 ca = find_cc(a);
    u64 cb = find_cc(b);

    if (ca != cb) {
        ++bridges;
        if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
            swap(a, b);
            swap(ca, cb);
        }
        make_root(a);
        par[a] = dsu_cc[a] = b;
        dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
        merge_path(a, b);
    }
}
 
int main(int argc, char *argv[])
{
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    u64 n, m;
    cin >> n >> m;
    init(n);
    
    vector<u64> A(m),B(m);
    for (u64 i = 0; i < m; i++) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    
    vector<u64> cnt(m);
    cnt[m - 1] = n*(n - 1)/2;
    for (u64 i = m - 1; i >= 1; i--) {
        u64 a, b, ca, cb;
        a = find_2ecc(A[i]);
        b = find_2ecc(B[i]);
        ca = find_cc(a);
        cb = find_cc(b);
        if (ca != cb) {
            cnt[i - 1] = cnt[i] - dsu_cc_size[ca] * dsu_cc_size[cb];
        } else {
            cnt[i - 1] = cnt[i];
        }
        add_edge(A[i], B[i]);
    }
    
    for (u64 i = 0; i < m; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}
