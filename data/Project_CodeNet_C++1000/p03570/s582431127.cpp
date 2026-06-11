#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5 + 7);
const int nAlpha = 'z' - 'a' + 1;
const int mod = int(1e9 + 7);

unordered_map<int, int> minf;
int f, sumxor, n;
string s;

int Get(int x) {
    if(minf.count(x)) return minf[x];
    return N;
}

void Update(int x, int f) {
    if(minf.count(x)) minf[x] = min(minf[x], f);
    else minf[x] = f;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s; n = int(s.size());
    s = ' ' + s; minf[0] = 0;
    for(int i = 1; i <= n; ++i) {
        s[i] -= 'a';
        sumxor ^= (1 << s[i]);
        f = min(Get(sumxor) + 1, f + 1);
        for(int j = 0; j < nAlpha; ++j) f = min(f, Get(sumxor ^ (1 << j)) + 1);
        Update(sumxor, f);
    }
    cout << f;
}
