#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int, ll>> v(n);
    REP(i,n){
        cin >> v[i].second >> v[i].first;
    }
    sort(ALL(v));
    reverse(ALL(v));
    ll now = 0;
    set<int> s;
    multiset<ll> used;
    for(int i = 0; i < k; i++){
        now += v[i].first;
        if(s.count(v[i].second)) used.insert(v[i].first);
        else s.insert(v[i].second);
    }
    now += s.size() * s.size();
    ll ans = now;
    for(int i = k; i < n; i++){
        if(used.size() == 0) break;
        if(!s.count(v[i].second)){
            now -= *used.begin();
            used.erase(used.begin());
            s.insert(v[i].second);
            now += v[i].first;
            now += s.size() * s.size() - (s.size() - 1) * (s.size() - 1);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}