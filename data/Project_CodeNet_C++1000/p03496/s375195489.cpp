#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int pval = 0, pid = -1;
    int mval = 0, mid = -1;
    rep(i,n){
        if(a[i] >= 0) {
            if(a[i] > pval){
                pval = a[i];
                pid = i;
            }
        }
        if(a[i] <= 0){
            if(abs(a[i]) > mval){
                mval = abs(a[i]);
                mid = i;
            }
        }
    }
    vector<P> res;
    if(pval > mval){
        rep(i,n){
            //全部正に
            if(a[i] < 0){
                //a[i] += a[pid];
                res.push_back(P(pid, i));
            }
        }
    }else{
        rep(i,n){
            //全部負に
            if(a[i] > 0){
                //a[i] += a[mid];
                res.push_back(P(mid, i));
            }
        }
    }
    //累積和
    if(pval > mval){
        for(int i = 0; i < n-1; i++) res.push_back(P(i,i+1));
    }else{
        for(int i = n-1; i >= 1; i--) res.push_back(P(i,i-1));
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i){
        cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
    }
}