#include <bits/stdc++.h>
using namespace std;

#define int long long
//typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
 
#if 1
//-------------
// DUMPマクロ
// https://www.creativ.xyz/dump-cpp-652/
 
// vector
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&& ... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#endif

int N;
vector<int> a,b,c;
vector<vector<int>> G;

signed main() {
    cin >> N;
    a.assign(N-1,0);
    b.assign(N-1,0);
    c.assign(N,0);
    G.assign(N,vector<int>());
    vector<int> cnt(N,0);
    rep(i,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        cnt[a[i]]++; cnt[b[i]]++;
    }
    rep(i,N) cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    int now=0;
    vector<int> ans(N,0);
    
    int start=-1;
    rep(i,N){
        if(cnt[i]==1){ start=i; break;}
    }
    
    vector<bool> seen(G.size(), false);
    queue<int> q;
    q.push(start);
    seen[start] = true;
    ans[start] = c[now++];

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            if (seen[v]) continue;
            else {
                q.push(v);
                seen[v] = true;
                ans[v] = c[now++];
            }
        }
    }
    int s = 0;
    rep(i,N-1)
        s+= c[i+1];
    cout << s << endl;
    rep(i,N) cout << ans[i] << endl;

}
