#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n, m;
string s;
vector<int> e[200000];
pi cnt[200000];
bool dead[200000];

int main() {
    cin >> n >> m >> s;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
        if (s[b] == 'A') cnt[a].first++;
        else cnt[a].second++;
        if (a != b) {
            if (s[a] == 'A') cnt[b].first++;
            else cnt[b].second++;
        }
    }
    while (true) {
        bool end = true;
        rep(i,n) {
            if (dead[i]) continue;
            if (cnt[i].first > 0 && cnt[i].second > 0) continue;
            end = false;
            dead[i] = true;
            queue<int> que;
            rep(j,e[i].size()) {
                if (dead[e[i][j]]) continue;
                if (s[i] == 'A') cnt[e[i][j]].first--;
                else cnt[e[i][j]].second--;
                if (cnt[e[i][j]].first == 0 || cnt[e[i][j]].second == 0) {
                    dead[e[i][j]] = true;
                    que.push(e[i][j]);
                }
            }
            while (!que.empty()) {
                int q = que.front(); que.pop();
                rep(j,e[q].size()) {
                    if (dead[e[q][j]]) continue;
                    if (s[q] == 'A') cnt[e[q][j]].first--;
                    else cnt[e[q][j]].second--;
                    if (cnt[e[q][j]].first == 0 || cnt[e[q][j]].second == 0) {
                        dead[e[q][j]] = true;
                        que.push(e[q][j]);
                    }
                }
            }
        }
        if (end) break;
    }
    rep(i,n) {
        if (!dead[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}