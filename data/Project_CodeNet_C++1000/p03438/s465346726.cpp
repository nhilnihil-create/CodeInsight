#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll diff = accumulate(b.begin(), b.end(), 0ll);
    diff -= accumulate(a.begin(), a.end(), 0ll);
    if (diff < 0) {
        puts("No");
        return 0;
    }
    if (diff == 0) {
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                can = false;
            }
        }
        puts(can ? "Yes" : "No");
        return 0;
    }
    ll oneup = 0, twoup = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] > b[i]){
            oneup += a[i] - b[i];
            continue;
        }
        if(a[i] < b[i]){
            twoup += (b[i] - a[i] + 1) / 2;
        }
    }
    puts(oneup <= diff && twoup <= diff ? "Yes" : "No");
}