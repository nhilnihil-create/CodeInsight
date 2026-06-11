#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> c(n),s(n),f(n),ans(n);
    rep(i,n-1){
        cin >> c[i] >>s[i]>> f[i];
    }
    rep(i,n-1){
        int cnt = s[i];cnt+=c[i];
        for(int j = i+1; j<n-1;++j){
            if(cnt<s[j]){
                cnt=s[j];
            }else if(cnt%f[j]==0);
            else{
                cnt+=f[j] - cnt%f[j];
            }
            cnt+=c[j];
        }
        ans[i] = cnt;
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}