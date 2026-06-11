#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),d;
    map<ll,ll> p;
    vector<P> q;
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    rep(i,m){
        ll b,c;
        cin >> b >> c;
        q.push_back({c,b});
    }
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    int cnt=0,cnt1=0;
    bool ok=false;
    while(1){
        int x=q[cnt1].second;
        while(1){
            d.push_back(q[cnt1].first);
            --x;
            ++cnt;
            if(cnt==n){
                ok=true;
                break;
            }
            if(x==0) break;
        }
        if(ok) break;
        ++cnt1;
    }
    ll ans=0;
    rep(i,n){
        ans+=max(a[i],d[i]);
    }
    cout << ans << "\n";
    return 0;
}   