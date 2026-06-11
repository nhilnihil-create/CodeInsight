#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll n;
    cin >> n;
    VL a(n), b(n), c(n);
    
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll suma = accumulate(ALL(a), 0LL);
    ll sumb = accumulate(ALL(b), 0LL);
    if(sumb > suma) {
        cout << -1 << endl;
        return 0;
    }

    VL diff(n);
    rep(i, 0, n) diff[i] = a[i] - b[i];
    sort(ALL(diff));
    ll neg = 0, ans = 0;
    rep(i, 0, n) {
        cerr << diff[i] << " ";
        if(diff[i] < 0){
            neg -= diff[i];
            ans++;
        }else{
            break;
        }
    }    
    cerr << endl;
    reverse(ALL(diff));
    ll pos = 0;
    rep(i, 0, n){
        if(pos < neg) {
            pos += diff[i];
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}