#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

char str[MAXN + 1];

vector <int> g[MAXN + 1];
int fr[MAXN + 1][2];
bool vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m >> str + 1;
    for(i = 1; i <= n; i++) {
        str[i] -= 'A';
    }
    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        fr[x][str[y]]++;
        fr[y][str[x]]++;
    }
    queue <int> Q;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        if(fr[i][0] && fr[i][1]) {
            continue;
        }
        vis[i] = 1;
        Q.push(i);
    }
    while(!Q.empty()) {
        cnt++;
        int nod = Q.front();
        Q.pop();
        for(auto it : g[nod]) {
            fr[it][str[nod]]--;
            if(fr[it][0] && fr[it][1]) {
                continue;
            }
            if(vis[it] == 0) {
                vis[it] = 1;
                Q.push(it);
            }
        }
    }
    if(cnt < n) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    //cin.close();
    //cout.close();
    return 0;
}
