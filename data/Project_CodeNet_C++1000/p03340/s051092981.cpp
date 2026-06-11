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
    vector<vector<int>> sum(20, vector<int>(n+1));
    rep(i,n){
        rep(j,20) if(a[i] >> j & 1) sum[j][i+1]++;
        rep(j,20) sum[j][i+1] += sum[j][i];
    }

    ll ans = 0;
    rep(i,n){
        int cnt = 1e9;
        rep(j,20){
            int idx = upper_bound(sum[j].begin(), sum[j].end(), sum[j][i]+1) - sum[j].begin();
            cnt = min(cnt, idx-1-i);
        }
        ans += cnt;
    }
    cout << ans << endl;
}