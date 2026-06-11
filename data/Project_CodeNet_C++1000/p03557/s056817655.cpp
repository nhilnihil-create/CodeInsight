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
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1), C(N+1);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);
    sort(all(A));
    sort(all(B));
    sort(all(C));
    A.push_back(INF);
    B.push_back(INF);
    C.push_back(INF);

    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ll an = 0, cn = 0;
        int b = B.at(i);

        int l = 0, r = N + 1;
        while( r - l > 1){
            int m = (l + r)/2;
            if(A.at(m) < b) l = m;
            else r = m;
        }
        an = l;

        l = 0, r = N + 1;
        while( r - l > 1){
            int m = (l + r)/2;
            if(C.at(m) > b) r = m;
            else l = m;
        }
        cn = N - r + 1;

        ans += an * cn;
    }

    cout << ans << endl;
}