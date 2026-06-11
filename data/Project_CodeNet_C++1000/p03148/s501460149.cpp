#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll,pair<ll, ll>> lpll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

#define deg_to_rad(deg) (((deg)/360)*2*PI)

const ll LINF = LLONG_MAX;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;

const ld PI = (acos(-1));
const ld EPS = 0.0000000001;
// cout << fixed << setprecision(10) << middle << endl;

int main() {
    // input, ready
    int N,K;
    cin >> N >> K;
    vector<pll> sushi(N);
    for (int i=0; i<N; i++) {
        ll t,d;
        cin >> t >> d;
        sushi[i] = {d,t};
    }
    sort(sushi.begin(),sushi.end());
    reverse(sushi.begin(),sushi.end());
    map<ll,ll> sushi_type;

    //resolve
    ll ans=0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i=0; i<K; i++) {
        pll st = sushi[i];
        ans += st.first;
        if (sushi_type[st.second]>0) pq.push(st);
        sushi_type[st.second]++;
    }
    ans += pow(sushi_type.size(),2);

    ll tmp = ans;
    for (int i=K; i<N; i++) {
        if (pq.size() == 0) break;
        if (sushi_type[sushi[i].second]>0) continue;
        auto st = pq.top(); pq.pop();
        tmp -= st.first;
        tmp += sushi[i].first;
        sushi_type[sushi[i].second]++;
        tmp -= pow(sushi_type.size()-1,2);
        tmp += pow(sushi_type.size(),2);
        ans = max(ans,tmp);
        //cout << tmp << endl;
    }

    // output
    cout << ans << endl;

    return 0;
}
