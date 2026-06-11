#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    rep(i, 0, A) cin >> s[i];
    rep(i, 0, B) cin >> t[i];
    rep(q, 0, Q){
        ll x; cin >> x;
        auto jin = lower_bound(s.begin(), s.end(), x);
        auto ter = lower_bound(t.begin(), t.end(), x);
        ll c1 = 1e18, c2 = 1e18, c3 = 1e18, c4 = 1e18;
        if(jin != s.end() && ter != t.end()){
            c1 = max(*jin, *ter) - x;
        }
        if(jin != s.begin() && ter != t.begin()){
            c2 = x - min(*(jin-1), *(ter-1));
        }
        if(jin != s.begin() && ter != t.end()){
            c3 = 2 * min(x - *(jin-1), *ter - x) + max(x - *(jin-1), *ter - x);
        }
        if(jin != s.end() && ter != t.begin()){
            c4 = 2 * min(x - *(ter-1), *jin - x) + max(x - *(ter-1), *jin - x);
        }
        cout << min({c1, c2, c3, c4}) << endl;
    }
    return 0;
}