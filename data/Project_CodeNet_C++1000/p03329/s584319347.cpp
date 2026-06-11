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
    vector<int> dp(100010, INF);
    dp.at(0) = 0;
    for(int i = 0; i <= N; i++){
        for(int c6 = 1; i + c6 <= N; c6 *= 6){
            dp.at(i + c6) = min(dp.at(i + c6), dp.at(i) + 1);
        }
        for(int c9 = 1; i + c9 <= N; c9 *= 9){
            dp.at(i + c9) = min(dp.at(i + c9), dp.at(i) + 1);
        }
    }

    cout << dp.at(N) << endl;
}