#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

int main(){
    int const INF = 100000000;
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int mn = INF;
    int mnidx;
    int mx = -INF;
    int mxidx;
    vector<P> ans;
    rep(i, n){
        if (a[i] >= mx){
            mx = a[i];
            mxidx = i;
        }
        if (a[i] <= mn){
            mn = a[i];
            mnidx = i;
        }
    }
    // cout << mx << " " << mn << endl;
    if (abs(mx) > abs(mn)){
        rep(i, n){
            if (i != mxidx && a[i] < 0){                                
                a[i] += mx;
                ans.push_back(P(mxidx, i));
            }
        }
        if (mxidx != 0){
            a[0] += mx;
            ans.push_back(P(mxidx, 0));
        }
        for (int i = 1; i < n; i++){
            a[i] += a[i-1];
            ans.push_back(P(i - 1, i));
        }
    }else{
        rep(i, n){
            if (i != mnidx){
                a[i] += mn;
                ans.push_back(P(mnidx, i));
            }
        }
        if (mnidx != n - 1){
            a[n-1] += mn;
            ans.push_back(P(mnidx, n - 1));        
        }
        for (int i = n - 2; i >= 0; i--){
            a[i] += a[i+1];
            ans.push_back(P(i + 1, i));
        }
    }
    // rep(i, n) cout << a[i] << " ";
    // cout << endl;
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}