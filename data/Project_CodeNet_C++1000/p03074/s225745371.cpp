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

int main(){
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<ll> back(1);
    back[0] = 0;
    ll ans = 0;
    ll cnt = 0;

    rep(i, n){
        if(s[i] == '0'){
            cnt++;
            while(s[i] == '0')i++;
            back.push_back(i);
            if(cnt > k){
                back.erase(back.begin());
                cnt = k;
            }
        }
        ll len = i - back.front() + 1;
        if(i == n)len--;
        ans = max(ans, len);
    }
    
    cout << ans << endl;
}