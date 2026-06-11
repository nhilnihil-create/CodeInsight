#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[10010];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];

    int ans = 0;
    for (int i=0;i<n;i++) {
        while (a[i]%2==0) a[i] /= 2, ans++;
    }

    cout << ans << endl;
}
