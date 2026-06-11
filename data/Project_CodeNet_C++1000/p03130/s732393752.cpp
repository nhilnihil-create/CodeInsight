#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;


int main(){
    vector<ll> ans(4);
    rep(i,3){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        ans[a]++;
        ans[b]++;
    }
    ll cnt_one=0,cnt_two=0;
    rep(i,4){
        if(ans[i]==1) cnt_one++;
        if(ans[i]==2) cnt_two++;
    }
    if(cnt_one==2 && cnt_two==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}