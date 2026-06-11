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
    ll N;
    cin >> N;
    vector<ll> cards(N);
    for( ll i = 0; i < N; ++ i ){
        cin >> cards[i];
    }
    sort(cards.rbegin(), cards.rend());

    vector<ll> sums(2,0);
    for ( ll i = 0; i < cards.size(); ++ i ){
        sums[i%2] += cards[i];
    }
    cout << sums[0]-sums[1] << endl;

    return 0;
}