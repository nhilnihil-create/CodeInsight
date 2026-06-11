#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD=1000000007;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
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
int main()
{
    ll N, K;
    cin >> N >> K;

    map<ll, ll > balls;
    for ( ll i = 0; i < N; ++ i ){
        ll n;
        cin >> n;
        balls[n]++;
    }
    vector<pair<ll,ll>> sortedBalls;
    copy(balls.begin(), balls.end(),back_inserter<vector<pair<ll,ll>>>(sortedBalls));

    sort(sortedBalls.begin(), sortedBalls.end(), [](const auto &a, const auto&b ){return a.second < b.second; });

#ifdef SOURCE_TEST
    
    for ( auto& v : sortedBalls ){
        cout << v.first << ":" << v.second << endl;
    }
#endif

    ll diff = sortedBalls.size() - K;
    ll count = 0;
    for ( ll i = 0; i < diff; ++ i ){
        count += sortedBalls[i].second;
    }
    cout << count << endl;

    return 0;
}