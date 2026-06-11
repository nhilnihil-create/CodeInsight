#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;

int n;
int a[N];
ll ans;
ll ps[N];
map<ll, int> freq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    sort(ps, ps + n + 1);
    ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += freq[ps[i]];
        freq[ps[i]]++;
    }
    cout << ans << "\n";
}