#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    int l = 1, r = n;

    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        l = max(l, a);
        r = min(r, b);
    }

    cout << max(0, r-l+1) << endl;
}
