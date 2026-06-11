#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool a) {
    return a ? "T" : "F";
}

string to_string(const char* s) {
    return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define X first
#define Y second

using ll = long long;
using ld = long double;

const int N = 1e5 + 10;

int n;
int l[N], r[N];
set < pair <int, int> > st[2], mem[2];

pair <int, int> get0(int p) {
    if (st[0].empty()) return make_pair(0, -1);
    auto it = --st[0].end();
    if (it->X > p) return *it;
    return make_pair(0, -1);
}

pair <int, int> get1(int p) {
    if (st[1].empty()) return make_pair(0, -1);
    auto it = st[1].begin();
    if (it->X < p) return *it;
    return make_pair(0, -1);
}

pair <int, int> (*get[2])(int) = {get0, get1};

void run() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", l + i, r + i);
        mem[0].emplace(l[i], i);
        mem[1].emplace(r[i], i);
    }

    for (int i = 1; i <= n; ++i) debug(l[i], r[i], i);

    ll ans = 0;
    for (int _ = 0; _ < 2; ++_) {
        st[0] = mem[0];
        st[1] = mem[1];
        int nw = _;
        ll tmp = 0;
        int pos = 0;
        while (1) {
            auto p = ::get[nw](pos);
            debug(p, pos, nw, st[0], st[1]);
            if (p == make_pair(0, -1))
                break;
            st[nw].erase(p);
            st[1 - nw].erase(make_pair((nw == 0 ? r : l)[p.Y], p.Y));
            tmp += abs(p.X - pos);
            pos = p.X;
            nw = 1 - nw;
        }
        tmp += abs(pos);
        maxi(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main() {
    run();

    return 0;
}
