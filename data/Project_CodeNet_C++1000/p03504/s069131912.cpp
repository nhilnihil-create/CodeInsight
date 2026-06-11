#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    ll n, c;
    cin >> n >> c;

    vector<ll> s(n), t(n), ch(n);
    rep(i, n)cin >> s[i] >> t[i] >> ch[i];

    vector<ll> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll x, ll y){
        return s[x] < s[y];
    });

    vector<pll> recoder;
    recoder.push_back(make_pair(t[ord[0]], ch[ord[0]]));

    for(ll i = 1; i < n; ++i){
        ll pos = ord[i];
        bool find_ch = false;
        rep(j, recoder.size()){
            if(recoder[j].first < s[pos]){
                find_ch = true;
                recoder[j].first = t[pos];
                recoder[j].second = ch[pos];
                break;
            }
            else if(recoder[j].first == s[pos] & recoder[j].second == ch[pos]){
                find_ch = true;
                recoder[j].first = t[pos];
                break;
            }
        }
        if(!find_ch){
            recoder.push_back(make_pair(t[pos], ch[pos]));
        }
    }

    cout << recoder.size() << endl;
}