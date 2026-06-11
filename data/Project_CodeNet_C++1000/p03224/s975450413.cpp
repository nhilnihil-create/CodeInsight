#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5 + 5;
const int inf = 1e9;
typedef long long ll;
typedef double db;

void solve() {
    int n;

    while (cin >> n) {
        int tmp = n * 2;
        int k = -1;
        for (int i = 2; ; i++) {
            if (i * (i-1) > tmp) break;
            if (i * (i-1) == tmp) {
                k = i;
            }
        }
        if (k == -1) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            cout << k << endl;
            int cur = 1;
            vector<int> G[1005];
            for (int i = 1; i <= k; i++) {
                int cnt = 0;
                for (int j = 0; j < k-1; j++) {
                    cnt++;
                    if (cnt <= i - 1) {
                        G[i].push_back(G[cnt][i-2]);
                    }
                    else {
                        G[i].push_back(cur++);
                    }
                }
            }
            for (int i = 1; i <= k; i++) {
                printf("%d", k-1);
                for (int j = 0; j < G[i].size(); j++) {
                    printf(" %d", G[i][j]);
                }
                puts("");
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t= 1;
    //scanf("%d",&t);
    while(t--) {
        solve();
    }
}
