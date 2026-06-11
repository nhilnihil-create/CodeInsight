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
    vector<int> A(100010), D(100010);
    for(int i = 1; i <= N; i++) cin >> A.at(i);
    for(int i = 1; i <= N; i++){
        int e1 = abs(A.at(i - 1) - A.at(i));
        int e2 = abs(A.at(i) - A.at(i + 1));
        int e3 = abs(A.at(i - 1) - A.at(i + 1));
        D.at(i) = e1 + e2 - e3;
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        ans += abs(A.at(i + 1) - A.at(i));
    }

    for(int i = 1; i <= N; i++){
        cout << ans - D.at(i) << endl;
    }
}