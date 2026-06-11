#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    vector<ll> V;
    ll suf = 0, insuf = 0, tot = 0;
    rep(i, n) {
        int a = A[i] - B[i];
        if(a > 0) {
            suf += a;
            V.push_back(a);
        }
        if(a < 0) {
            insuf += abs(a);
            tot++;
        }
    }
    if(suf - insuf < 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ALL(V), greater<ll>());
    ll ans = tot;
    rep(i, V.size()) {
        if(insuf <= 0) break;
        insuf -= V[i];
        ans++;
    }

    cout << ans << endl;

    return 0;
}