#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int n, a, b, c;
int l[10];
const int INF = 1<<30;
int ans = INF;

void dfs(int x, int y, int z, int mp, int i) {
    if (i == n) {
        if (x == 0 || y == 0 || z == 0) return;

        int res = mp;
        res += abs(x-a);
        res += abs(y-b);
        res += abs(z-c);
        ans = min(ans, res);
        return;
    }
    
    dfs(x+l[i], y, z, x==0? mp:mp+10, i+1);
    dfs(x, y+l[i], z, y==0? mp:mp+10, i+1);
    dfs(x, y, z+l[i], z==0? mp:mp+10, i+1);
    dfs(x, y, z, mp, i+1);
}

int main() 
{
    cin >> n >> a >> b >> c;
    rep(i,n) cin >> l[i];

    dfs(0, 0, 0, 0, 0);

    cout << ans << endl;

    return 0;
}
