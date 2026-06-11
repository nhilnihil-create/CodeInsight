#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];
    double sum = 0;
    rep(i, 0, n) sum += a[i];
    sum /= n;
    double sa = 99999999; int m = 0;;
    rep(i, 0, n){
        if(abs(a[i]-sum) < sa){
            sa = abs(a[i]-sum);
            m = i;
        }
    }
    cout << m << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
