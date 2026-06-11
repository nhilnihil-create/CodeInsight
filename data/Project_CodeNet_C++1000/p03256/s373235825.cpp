#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M;
string s;
int a[220000], b[220000];
vint G[220000];
int nA[220000], nB[220000];

void dfs(int x) {
    if (nA[x] != 0 && nB[x] != 0)return;
    nA[x] = nB[x] = 0;
    for (int i = 0; i < G[x].size(); i++) {
        if (x == G[x][i])continue;
        if (nA[G[x][i]] == 0 && nB[G[x][i]] == 0)continue;
        if (s[x] == 'A')nA[G[x][i]]--;
        else nB[G[x][i]]--;
        dfs(G[x][i]);
    }
}

signed main() {
    cin >> N >> M >> s;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        if (s[a[i]] == 'A')nA[b[i]]++;
        else nB[b[i]]++;
        if (s[b[i]] == 'A')nA[a[i]]++;
        else nB[a[i]]++;
    }
    for (int i = 0; i < N; i++) {
        if (nA[i] == 0 && nB[i] == 0)continue;
        dfs(i);
    }
    for (int i = 0; i < N; i++) {
        if (nA[i] != 0 && nB[i] != 0) {cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
    return 0;

}
