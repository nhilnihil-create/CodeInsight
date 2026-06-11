#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 21
#define M 300300
int a[N][N], n;
ll Sum[M], f[M];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (int s = 0; s < (1 << n); s++) {
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (s >> i & 1ll) v.push_back(i);
        ll sum = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++) sum += a[v[i]][v[j]];
        Sum[s] = sum;
    }
    for (int s = 0; s < (1 << n); s++) {
        f[s] = Sum[s];
        for (int k = s; k; k = (k - 1) & s) f[s] = max(f[s], f[s ^ k] + Sum[k]);
    }
    printf("%lld\n", f[(1 << n) - 1]);
    return 0;
}