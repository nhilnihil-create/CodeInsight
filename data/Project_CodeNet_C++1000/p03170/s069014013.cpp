#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    nfs
    int i, j, n, k, a[101] = {};
    bool out[mx5] = {};
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    out[0] = 0;
    for (i = 1; i <= k; i++) {
        for (j = 0; j < n && a[j] <= i; j++) {
            if (!out[i - a[j]]) {
                out[i] = 1;
                break;
            }
        }
    }
    cout << (out[k] ? "First" : "Second");
}
