#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
ll sum = 0;
int ans[20000];

int main() {
    cin >> n;
    int now = 1;
    rep(i,n-2) {
        now++;
        while (now%2 != 0 && now%3 != 0 && now%5 != 0) now++;
        ans[i] = now;
        sum += now;
    }
    now++;
    while ((now%2 != 0 && now%3 != 0 && now%5 != 0) || ((sum+now)%2 != 0 && (sum+now)%3 != 0 && (sum+now)%5 != 0)) now++;
    ans[n-2] = now;
    sum += now;

    for (int i = now+1;; i++) {
        if ((sum + i)%2 == 0 && (sum+i)%3 == 0 && (sum+i)%5 == 0 && (i%2 == 0 || i%3 == 0 || i%5 == 0)) {
            ans[n-1] = i;
            break;
        }
    }
    rep(i,n) {
        cout << ans[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
}