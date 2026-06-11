#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll A = 0, B = 0;
    rep(i,n) {
        if(a[i] > b[i]) A+=a[i]-b[i];
        if(b[i] > a[i]) B+=(b[i]-a[i])/2;
    }
    if(A <= B) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}