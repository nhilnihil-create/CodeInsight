#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    vector<ll> d(N);

    ll ans = 0;
    rep(i, N) d.at(i) = A.at(i) - B.at(i);
    sort(d.begin(), d.end());

    ll m = 0;
    rep(i, N) if(d.at(i)<0){
        m += d.at(i)*(-1ll);
        ans++;
    }

    int i = N-1;
    while(m>0){
        if(d.at(i)>0) m -= d.at(i);
        ans++;
        i--;
        if(i==0) break;
    }

    if(m>0) cout << -1 << endl;
    else cout << ans << endl;
}