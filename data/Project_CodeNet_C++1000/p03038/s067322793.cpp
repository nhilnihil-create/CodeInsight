#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main(){
ll n,m;
cin >> n >> m;
priority_queue<ll, vector<ll>,greater<ll>> pq;
for (ll i = 0; i < n;i++){
    ll t;
    cin >> t;
    pq.push(t);
}
vector<pair<ll, ll>> query(m);
for (ll i = 0; i < m;i++){
    ll b, c;
    cin >> b >> c;
    query[i].first = c;
    query[i].second = b;
}
sort(query.begin(), query.end(),greater<pair<ll,ll>>());
for (ll i = 0; i < m; i++) {
    for (ll j = 0; j < query[i].second;j++){
        ll t = pq.top();
		if(query[i].first>t){
            pq.pop();
            pq.push(query[i].first);
        }
		else
            break;
    }
}
ll ans = 0;
while(!pq.empty()){
	ans+=pq.top();
    pq.pop();
}
cout << ans << endl;
}