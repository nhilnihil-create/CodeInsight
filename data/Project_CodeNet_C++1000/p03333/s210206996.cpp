#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;
int l[maxn], r[maxn];
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i];
    }
    l[n + 1] = 0, r[n + 1] = 0;
    n++;
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    ll ans = 0;
    for(int i = 1;i < n + 1 - i;i++){
        ans += max(0, l[n + 1 - i] - r[i]);
    }
    ans = ans * 2;
    cout << ans << endl;
    return 0;
}
