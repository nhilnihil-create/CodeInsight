#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;

    vector<ll> A,B;
    ll asum,bsum;
    asum = bsum = 0;
    ll ans = 0;
    vector<ll> suf;
    ll res = 0;

    rep(i,N) {
        int a;
        cin >> a;
        A.push_back(a);
        asum+=a;
    }
    rep(i,N) {
        int b;
        cin >> b;
        B.push_back(b);
        bsum+=b;
    }

    rep(i,N) {
        ll a = A[i];
        ll b = B[i];

        if (a>b) suf.push_back(a-b);
        else if (a<b) {
            res += b-a;
            ans++;
        }
    }
    sort(suf.begin(),suf.end());
    reverse(suf.begin(),suf.end());

    for (int i=1; i<suf.size(); i++) {
        suf[i] = suf[i-1]+suf[i];
    }


    if (asum<bsum) cout << -1 << endl;
    else if (res==0) cout << 0 << endl;
    else {
        int idx = 0;

        rep(i,suf.size()) {
            if (suf[i]>=res) {
                idx = i;
                break;
            }
        }
        ans += idx + 1;
        cout << ans << endl;
    }
}