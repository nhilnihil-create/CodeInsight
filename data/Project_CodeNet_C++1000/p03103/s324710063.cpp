#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
int main(){

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> s(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        s[i] = make_pair(a, b);
    }

    sort(s.begin(), s.end());
    ll cost = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt < m){
            cnt += s[i].second;
            cost += s[i].first * s[i].second;
        }
        while(cnt > m){
            cnt--;
            cost -= s[i].first;
        }
        if(cnt == m) break;
    }
    cout << cost << endl;
    return 0;
}