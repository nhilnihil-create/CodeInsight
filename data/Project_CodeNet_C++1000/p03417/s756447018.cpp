#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    ll N, M;
    cin >> N >> M;
    if(N == 1 && M == 1) cout << 1 << endl;
    else if(N == 1) cout << M - 2 << endl;
    else if(M == 1) cout << N - 2 << endl;
    else cout << (N - 2)*(M-2) << endl;

}