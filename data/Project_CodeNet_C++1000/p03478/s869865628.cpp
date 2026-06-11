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

ll digitSum( ll v ){
    ll sum = 0;
    for( ; v > 0; v /= 10 ){
        sum += v % 10;
    }
    return sum;
}
int main()
{
    ll N, A, B;
    cin >> N >> A>> B;

    ll sum = 0;
    for ( ll i = 1; i <= N; ++ i ){
        auto v = digitSum(i);
        if ( A <= v && v <= B ){
            sum += i;
        }
    }
    cout << sum << endl;


    return 0;
}