#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << a[0] << b[1] << c[2];
}

int main() {
    fast_io;
    int t = 1;
//    cin >> t;
    int c = 1;
    while (t--) {
//        printf("Case %lld: ",c);
//        cout<<"Case "<<c<<": ";
        solve();
        c++;
    }
}