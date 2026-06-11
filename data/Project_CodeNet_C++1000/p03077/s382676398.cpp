#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    ll N;
    cin >> N;
    vector<ll> V(5);
    rep(i, 5) cin >> V.at(i);
    sort(all(V));
    ll ans = (N - 1) / V.at(0) + 5 ;
    cout << ans << endl;
}