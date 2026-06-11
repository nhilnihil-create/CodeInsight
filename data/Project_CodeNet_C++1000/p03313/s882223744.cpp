#include<bits/stdc++.h>
using namespace std;
const int MAXN = 18;

int sum[MAXN+1][1<<MAXN];
int boro[MAXN+1][1<<MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < (1<<n); i++) {
        cin >> boro[0][i];
        sum[0][i] = -1;
    }

    for (int p = 1; p <= n; p++) {
        for (int msk = 0; msk < (1<<n); msk++) {
            boro[p][msk] = boro[p-1][msk];
            sum[p][msk] = sum[p-1][msk];
            if (msk&(1<<(p-1))) {
                boro[p][msk] = max(boro[p][msk], boro[p-1][msk^(1<<(p-1))]);
                sum[p][msk] = max(sum[p][msk], boro[p-1][msk]+boro[p-1][msk^(1<<(p-1))]);
            }
        }
    }

    int mx = -1;
    for (int i = 1; i < (1<<n); i++) {
        mx = max(mx, sum[n][i]);
        cout << mx << "\n";
    }


    return 0;
}
