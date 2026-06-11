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

ll mul3(int a){
    ll ans = 1;
    rep(i, 3) ans *= a;
    return ans;
}

int main(){
    int N, K;
    cin >> N >> K;

    ll ans = 1;
    if(K % 2 == 1){
        int a = N / K;
        ans = mul3(a);
    } else {
        int a = N / K;
        int b = N / (K / 2) - a;
        ans = mul3(a) + mul3(b);
    }

    cout << ans << endl;
}