#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

struct edge {
    int to, cost;
};

int V;
vector<edge> G[1000000];
vector<edge> GG[1000000];
ll d[1000000];

void addedge(int st, int ed, int co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

void addedge2(int st, int ed, int co) {
    edge e;
    e.to = ed;
    e.cost = co;
    GG[st].push_back(e);
}

bool moji[1000000];

int h[1000000];
vector<int> tsorted;

bool tsort() {
    fill(h, h + V, 0);
    for (int i = 0; i < V; i++) {
        int len = G[i].size();
        for (int j = 0; j < len; j++) {
            h[G[i][j].to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < V; i++) {
        if (h[i] == 0) {
            que.push(i);
            tsorted.push_back(i);
        }
    }
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        int len = G[p].size();
        for (int i = 0; i < len; i++) {
            int mark = G[p][i].to;
            h[mark]--;
            if (h[mark] == 0) {
                que.push(mark);
                tsorted.push_back(mark);
            }
        }
    }
    int sortedsize = tsorted.size();
    if (sortedsize == V) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    V = 2 * N;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') {
            moji[i] = true;
        } else {
            moji[i] = false;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (moji[a - 1] == moji[b - 1]) {
            addedge2(a - 1, b - 1 + N, 1);
            addedge2(b - 1, a - 1 + N, 1);
        } else {
            addedge2(a - 1 + N, b - 1, 1);
            addedge2(b - 1 + N, a - 1, 1);
        }
    }
    for (int i = 0; i < V; i++) {
        int len = GG[i].size();
        set<int> s;
        for (int j = 0; j < len; j++) {
            s.insert(GG[i][j].to);
        }
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            int j = *itr;
            addedge(i, j, 1);
        }
    }
    bool ok = tsort();
    if (ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
