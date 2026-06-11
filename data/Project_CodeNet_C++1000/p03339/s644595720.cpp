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
    string S;
    cin >> N >> S;
    vector<int> E(N + 10), W(N + 10);
    for(int i = 1; i<= N; i++){
        W.at(i) = W.at(i - 1);
        if(S.at(i - 1) == 'W') W.at(i)++;
    }

    for(int i = N; i >= 1; i--){
        E.at(i) = E.at(i + 1);
        if(S.at(i - 1) == 'E') E.at(i)++;
    }

    int ans = INF;
    for(int i = 1; i<= N; i++){
        ans = min(ans, W.at(i - 1) + E.at(i + 1));
    }

    cout << ans << endl;
}