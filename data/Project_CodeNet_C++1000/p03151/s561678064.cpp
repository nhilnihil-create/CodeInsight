#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> d,e;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n){
        if(a[i]-b[i]>=0) e.push_back(a[i]-b[i]);
        else d.push_back(b[i]-a[i]); //足りてない
    }
    sort(e.begin(),e.end(),greater<int>());
    ll s = 0;
    for(auto dx: d) s+= dx;
    if(s==0){
        cout << 0 << endl;
        return 0;
    }
    ll es = 0;
    for(auto ex : e) es+= ex;
    if(es<s){
        cout << -1 << endl;
        return 0;
    }
    ll now = 0;
    int ans = d.size();
    rep(i, (int)e.size()){
        ans++;
        now+=e[i];
        if(now>=s)break;
    }
    cout << ans << endl;

    return 0;
}