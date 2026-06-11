#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<long long,long long>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> a(n);
    rep(i,n) {
        int A, B;
        cin >> A >> B;
        a[i].first = A;
        a[i].second = B;
    }
    sort(all(a));
    ll ans = 0;
    int d = 0;
    rep(i,n) {
        if(m>=(d + a[i].second)){
            d+=a[i].second;
            ans+=(ll)a[i].first*(ll)a[i].second;
        }
        else if(d==m) break;
        else{
            ans += (m-d)*a[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}