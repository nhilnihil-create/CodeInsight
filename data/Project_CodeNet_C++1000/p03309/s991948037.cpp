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
    vector<int> A(N);
    rep(i, N){
        int a;
        cin >> a;
        A.at(i) = a - (i + 1);
    }

    sort(all(A));

    int b = A.at(N/2);
    ll ans = 0;
    rep(i, N){
        ans += abs(A.at(i) - b);
    }

    cout << ans << endl;
}