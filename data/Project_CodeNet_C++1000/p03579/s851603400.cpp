// Template //
#include<bits/stdc++.h>
using namespace std;

// マクロ //
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define uniq(x) x.erase(unique(all(x)), x.end())
#define vsum(x) accumulate(all(x), 0)
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) (x) * (x)

// 型エイリアス //
using lint = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vli = vector<lint>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvc = vector<vc>;
using vpii = vector<pii>;
using msi = map<string, int>;

// 関数 //
int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

double distance(pii a, pii b) {
    double dist;
    dist = sqrt(x2(a.first - b.first) + x2(a.second - b.second));
    return dist;
}

lint perm(int a) {
    lint perm = 1;
    for (int i = a; i >= 1; i--) {
        perm *= i;
    }
    return perm;
}

lint comb(int n, int m) {
    return perm(n) / (perm(n - m) * perm(m));
}

// 定数 //
#define pi acos(-1)
// End of Template //

vi color;

bool isBipartite(vvi& graph, int n, int cl = 0) {
    color[n] = cl;
    for (auto x : graph[n]) {
        if (color[x] != -1) {
            if (color[x] == cl) return false;
            continue;
        }
        if (!isBipartite(graph, x, 1 - cl)) return false;
    }
    return true;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
        
    lint N, M;   
    cin >> N >> M;

    color.assign(N, -1);
    vvi graph(N);
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    bool f = false;
    rep(i, N) {
        if (color[i] != -1) continue;
        if (!isBipartite(graph, i)) {
            f = true;
        }
    }

    sort(color);
    lint cnt = 0;
    while (color[cnt] == 0) cnt++;

    cou((f ? N * (N - 1) / 2 - M : cnt * (N - cnt) - M));
}