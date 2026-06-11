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
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    rep(i, N) cin >> X.at(i);
    
    int ans = INF;
    rep(i, N - K + 1){
        int time = 0;
        time += abs(X.at(i + K - 1) - X.at(i));
        time += min(abs(X.at(i)), abs(X.at(i + K - 1)));
        ans = min(ans, time);
    }

    cout << ans << endl;
}