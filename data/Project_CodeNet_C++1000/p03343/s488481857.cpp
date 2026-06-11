#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
int main() {
    int n,k,q;cin >> n >> k >> q;
    vector<lli> a(n);
    rep(i,n)cin >> a[i];
    lli ans = 1e18;
    rep(i,n){
        vector<vector<lli>> tmps;
        vector<lli> tmp;
        for(int j = 0;j<n;j++){
            if(a[j] < a[i]){
                tmps.push_back(tmp);
                tmp.clear();
            }else {
                tmp.push_back(a[j]);
            }
        }
        tmps.push_back(tmp);
        tmp.clear();
        int q_ = q;
        vector<lli> cand;
        for(auto &s:tmps){
            if(s.size() < k){
                continue;
            }
            else {
                sort(s.begin(),s.end());
                reverse(s.begin(),s.end());
                for(int l = k-1;l < s.size();l++){
                    cand.push_back(s[l]);
                }
            }
        }
        if(cand.size() < q){
            continue;
        }
        sort(cand.begin(),cand.end());
        ans = min(ans,cand[q-1] - cand[0]);
    }
    cout << ans << endl;
}
