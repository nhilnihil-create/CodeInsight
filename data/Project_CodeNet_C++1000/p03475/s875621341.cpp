#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int n;
    cin >> n;
    vector<int> vc(n), vs(n), vf(n);
    rep(i, n-1) {
        cin >> vc[i];
        cin >> vs[i];
        cin >> vf[i];
    } 
    rep(i, n-1) {
        int ans = 0;
        rng(j, i, n-1) {
            if (ans <= vs[j]) ans = vs[j];
            else 
                ans = vs[j] + vf[j]*((ans - vs[j]+vf[j]-1)/vf[j]); 
            ans += vc[j];
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
    return 0;
}