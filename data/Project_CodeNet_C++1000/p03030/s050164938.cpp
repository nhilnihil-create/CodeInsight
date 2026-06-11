#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

bool my_compare(const tuple<string, int, int>&lt, const tuple<string, int, int> &rt) {
    if(get<0>(lt) != get<0>(rt)) return get<0>(lt) < get<0>(rt);
    else if(get<1>(lt) != get<1>(rt)) return get<1>(lt) > get<1>(rt);
}

int main() {
    int N; cin >> N;
    vector<tuple<string, int, int>> a;
    map<string, int> mp;
    rp(i, 1, N+1) {
        string S; int P;
        cin >> S >> P;
        tuple<string, int, int> t = make_tuple(S, P, i);
        a.emplace_back(t);
    }
    sort(a.begin(), a.end(), my_compare);
    for(auto x: a) {
        cout << get<2>(x) << endl;
    }
    return 0;
}