#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

string Long2Str(ll x){
    if(x <= 0)return "";
    char c = '0'+x%10;
    return Long2Str(x/10) + c;
}
string get_number(ll x){
    string s = Long2Str(x);
    while(s.size() < 6)s = '0' + s;
    return s;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<pll> pre(m);
    rep(i, m)cin >> pre[i].first >> pre[i].second;

    vector<ll> ord(m);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll x, ll y){
        return pre[x].second < pre[y].second;
    });

    vector<ll> cnt(100010, 0);
    vector<string> res(m);

    rep(i, m){
        ll  p = pre[ord[i]].first;
        res[ord[i]] = get_number(p);
        res[ord[i]] += get_number(cnt[p]+1);
        cnt[p]++;
    }

    rep(i, m)cout << res[i] << endl;
}