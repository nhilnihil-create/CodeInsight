#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pos;
    for (int shift = 0; shift < 3; shift++) {
        for (int i = 0; shift + i * 3 < n; i++) {
            pos.pb(shift + i * 3);        
        }
    }
    map<char,int> q;
    for (auto ch: s) {
        q[ch]++;
    }
    vector<pair<int,char>> b;
    for (auto x: q) {
        b.pb({x.S, x.F});
    }
    sort(all(b));
    reverse(all(b));

    int cur = 0;
    string answer(n, '0');
    for (auto x: b) {
        for (int i = 0; i < x.F; i++) {
            answer[pos[cur]] = x.S;
            cur++;
        }
    }


    bool ok = 1;

    for (int i = 0; i < n - 1; i++) {
        if (answer[i] == answer[i + 1]) {
            ok = 0;
        }
        if (i + 2 < n && answer[i] == answer[i + 2]) {
            ok = 0;
        }
    }

    if (ok) {
        puts("YES");
    }
    else {
        puts("NO");
    }
        











    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}
