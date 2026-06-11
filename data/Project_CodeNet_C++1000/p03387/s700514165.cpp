#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int A, B, C;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    int M = max({A, B, C});
    int d = 3*M-A-B-C;
    if (d%2==0) cout << d/2 << endl;
    else cout << (d+3)/2 << endl;
}