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
    int N;
    cin >> N;
    vector<int> march(5, 0);
    rep(i, N){
        string s;
        cin >> s;
        if(s[0] == 'M') march[0]++;
        else if(s[0] == 'A') march[1]++;
        else if(s[0] == 'R') march[2]++;
        else if(s[0] == 'C') march[3]++;
        else if(s[0] == 'H') march[4]++;
    }

    ll ans = 0;
    rep(i, 5){
        rep(j, 5){
            if(i == j) continue;
            ll tmp = 1;
            rep(k, 5){
                if(k != i && k != j) tmp *= march[k];
            }
            ans += tmp;
        }
    }

    cout << ans / 2  << endl;

}