#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int n,cnt=0;
    cin >> n;
    vector<P> a(n);
    vector<P> c(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    rep(i,n) cin >> c[i].first >> c[i].second;
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    rep(i,n){
        bool ok=false;
        int pr=-1,t;
        rep(j,n){
            if(c[i].first<a[j].first) continue;
            if(c[i].second<a[j].second) continue;
            if(pr<=a[j].second){
                pr=a[j].second;
                t=j;
                ok=true;
            }
        }
        if(ok){
            ++cnt;
            a[t].first=1000;
        }
    }
    cout << cnt << "\n";
    return 0;
}