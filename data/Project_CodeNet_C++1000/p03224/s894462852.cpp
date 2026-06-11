#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

int main() {
    int n,m,k; scanf("%d", &n);
    for (m = 1; m * m <= 8 * n + 1; m+=2) {
        if (m * m == 8 * n + 1) {
            break;
        }
    }
    if (m * m == 8 * n + 1) {
        k = (m + 1) / 2;
        vector<vector<int>> out(k + 1);
        puts("Yes");
        cout << k << endl;
        int index = 1;
        REP(i, k) {
            printf("%d ", k-1);
            REP(j, k-1) {
                if (j >= out[i].size()) {
                    printf("%d ",index);
                    out[i + j - out[i].size() + 1].push_back(index);
                    index++;
                }
                else {
                    printf("%d ", out[i][j]);
                }
            }
            printf("\n");
        }
    }
    else {
        puts("No");
    }
    getchar(); getchar();
}