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
    vector<int> X(N), Y(N);
    rep(i, N){
        int tmp;
        cin >> tmp;
        X.at(i) = tmp;
        Y.at(i) = tmp;
    }

    sort(all(Y));
    int m1 = Y.at(N/2 - 1), m2 = Y.at(N/2);

    rep(i, N){
        if(X.at(i) <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }

}