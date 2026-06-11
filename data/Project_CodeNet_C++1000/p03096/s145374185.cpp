#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 200050
#define Mo 1000000007
int n, a[N];
LL f[N];
unordered_map<int, LL> m;

int main() {
    //freopen("sample.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int tot = 1;
    for(int i = 2; i <= n; i++)
        if (a[i] != a[i - 1]) a[++tot] = a[i];
    f[0] = 1;
    for(int i = 1; i <= tot; i++) {
        f[i] = (f[i - 1] + m[a[i]]) % Mo;
        m[a[i]] = f[i];
    } 
    cout << f[tot] << endl;
}