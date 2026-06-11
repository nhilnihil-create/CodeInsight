#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}

ll flg[101010];

int main(){

    ll N, K;
    cin >> N >> K;
    priority_queue<P>Q;
    priority_queue<P, vector<P>, greater<P> >R;
    rep(i, N){
        ll t, d;
        cin >> t >> d;
        Q.push(P(d, t));        
    }
    ll v = 0, sum = 0;
    rep(i, K){
        ll d = Q.top().first;
        ll t = Q.top().second;
        Q.pop();
        sum += d;
        if(flg[t] == 0){
            flg[t] = 1;
            v++;
        }
        else R.push(P(d, t));
    }
    ll ans = sum + v * v;
    while(!Q.empty()){
        ll d = Q.top().first;
        ll t = Q.top().second;
        Q.pop();
        if(flg[t])continue;
        if(!R.empty()){
            ll rd = R.top().first;
            ll rt = R.top().second;
            R.pop();
            sum -= rd;
            sum += d;
            flg[t] = 1;
            v++;
        }
        chmax(ans, sum + v * v);
    }
    cout << ans << endl;
    return 0;
}