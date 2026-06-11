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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> L(n);
    rep(i, n) cin >> L.at(i);
    int ans = INF;
    for(int i = 0; i < (1 << (2 * n)); i++){
        int tmp = i;
        vector<vector<int>> bmb(4);
        rep(j, n){
            bmb.at(tmp % 4).push_back(L.at(j));
            tmp /= 4;
        }
        if(bmb.at(0).size() == 0 || bmb.at(1).size() == 0 || bmb.at(2).size() == 0) continue;
        
        int a_bmb = 0, b_bmb = 0, c_bmb = 0;

        rep(j, bmb.at(0).size()){
            a_bmb += bmb.at(0).at(j);
        }
        rep(j, bmb.at(1).size()){
            b_bmb += bmb.at(1).at(j);
        }
        rep(j, bmb.at(2).size()){
            c_bmb += bmb.at(2).at(j);
        }

        int mp = abs(a_bmb - a) + abs(b_bmb - b) + abs(c_bmb - c);
        rep(j, 3){
            mp += 10 * (bmb.at(j).size() - 1);
        }

        ans = min(ans, mp);
    }

    cout << ans << endl;    
}