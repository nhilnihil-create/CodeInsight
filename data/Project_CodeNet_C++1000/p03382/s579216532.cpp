#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int n;

void solve() {
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    sort(a, a+n);
    double h = 1. * a[n-1] / 2;
    int op = 0;
    rep(i,n-1) {
        if (abs(op - h) > abs(a[i] - h)) {
            op = a[i];
        }
    }
    cout << a[n-1] << " " << op << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
