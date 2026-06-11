#include<bits/stdc++.h>
using namespace std;

#define LL long long
char c[1001][1001];
int d[1000005], ans;
queue<int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> (c[i]+1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(c[i][j] == '#') {
                q.push((i - 1) * m + j);
                d[(i - 1) * m + j] = 1;
            }
        }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, d[u]);

        for(int i = 0; i < 4; i++) {
            int v = u;
            if(i==0 && v<=m || i==1 && v%m == 1%m || i==2 && u>=(n-1)*m+1 || i==3 && u%m==0)
                continue;
            if(i == 0) v -= m;
            else if(i == 1) --v;
            else if(i == 2) v += m;
            else v++;

            if(!d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    --ans;
    cout << ans;
}