#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, hp, maxim, ans, sum;
int a[N], b[N];
bool con;

int up(int a, int b) {
    if(a % b == 0) return a / b;
    return a / b + 1;
}

bool cmp(int x, int y) {
    return x > y;
}

void solve() {
    cin >> n >> hp;
    maxim = ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        maxim = max(maxim, a[i]);
    }
    sum = 0;
    con = true;
    sort(b + 1, b + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        if(b[i] >= maxim) {
            hp -= b[i];
            sum += b[i];
            ans++;
            if(hp <= 0) {
                con = false;
                break;
            }
        }
    }
    if(con) ans += up(hp, maxim);
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}