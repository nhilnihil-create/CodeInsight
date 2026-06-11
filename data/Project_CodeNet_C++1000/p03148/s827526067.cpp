#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}

int main(){

    ll N, K;
    cin >> N >> K;
    set<ll>S;
    vector<P>v(N);
    priority_queue<ll, vector<ll>, greater<ll> >R;
    rep(i, N)cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end(), greater<P>());
    ll sum = 0;
    rep(i, K){
        ll d = v[i].first;
        ll t = v[i].second;
        sum += d;
        if(S.find(t) != S.end())R.push(d);
        S.insert(t);
    }
    ll ans = sum + S.size() * S.size();
    for(ll i = K; i < N; i++){
        ll d = v[i].first;
        ll t = v[i].second;
        if(S.find(t) != S.end())continue;
        if(!R.empty()){
            ll r = R.top();
            R.pop();
            sum -= r;
            sum += d;
            S.insert(t);
        }
        chmax(ans, ll(sum + S.size() * S.size()));
    }
    cout << ans << endl;
    return 0;
}