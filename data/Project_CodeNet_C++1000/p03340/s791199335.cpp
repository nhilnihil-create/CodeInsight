#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> num(20, vector<int>(n));
    rep(i,n) rep(j,20) if(a[i] >> j & 1) num[j][i]++;

    ll ans = 0;
    vector<int> cnt(20);
    int idx = 0;
    rep(i,n){
        while(1){
            if(idx == n) break;
            bool flag = true;
            rep(j,20) if(cnt[j] + num[j][idx] > 1) flag = false;
            if(!flag) break;
            rep(j,20) cnt[j] += num[j][idx];
            idx++;
            if(idx == n) break;
        }
        ans += idx - i;
        rep(j,20) cnt[j] -= num[j][i];
    }
    cout << ans << endl;
}