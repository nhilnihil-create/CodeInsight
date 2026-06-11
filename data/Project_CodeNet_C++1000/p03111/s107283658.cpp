#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
int ans,n;
int a[3];
void dfs(ve<int> &l, string s){
    if(s.size() == n){
        ve<int> l0(4,0),cnt(4,0);
        rep(i,n){
            l0[s[i]-'0'] += l[i];
            cnt[s[i]-'0']++;
        }
        rep(i,3)if(cnt[i] == 0) return;
        int memo = 0;
        rep(i,3) {
            memo += 10 * (cnt[i]-1);
            memo += abs(a[i]-l0[i]);
        }
        ans = min(ans,memo);
        return;
    }
    dfs(l,s+'0');
    dfs(l,s+'1');
    dfs(l,s+'2');
    dfs(l,s+'3');
    return;
}

int main(){
    cin >> n >> a[0] >> a[1] >> a[2];
    ve<int> l(n);
    rep(i,n) cin >> l[i];
    ans = 1e9;
    dfs(l,"");
    cout << ans << endl;
    return 0;
}