#include<iostream> 
#include<vector> 
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m, k, t;
    cin >> n >> m;
    vector<int> p(n), on(n, 0);
    vector<vector<int>> s(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            s[i][t-1] = 1;
        }
    }

    for (int i = 0; i < m; i++) scanf("%d", &p[i]);

    int maxi = 1 << n;
    int ans = 0;
    for (int pat = 0; pat < maxi; pat++) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            int on = 0;
            for (int j = 0; j < n; j++) {
                if (s[i][j] && (pat >> j & 1)) on++;
            }
            if (on % 2 != p[i]) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}