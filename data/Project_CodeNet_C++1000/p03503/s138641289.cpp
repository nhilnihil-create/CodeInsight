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

    vector<vector<int>> F(N, vector<int>(10)), P(N, vector<int>(11));
    rep(i, N){
        rep(j, 10){
            cin >> F.at(i).at(j);
        }
    }
    rep(i, N){
        rep(j, 11){
            cin >> P.at(i).at(j);
        }
    }

    int ans = - INF;

    for(int tmp = 1; tmp < (1 << 10); tmp++){
        bitset<10> s(tmp);
        int profit = 0; 
        for(int i = 0; i < N; i++){
            int open = 0;
            for(int j = 0; j < 10; j++){
                if(s.test(j) && F.at(i).at(j)) open++;
            }
            profit += P.at(i).at(open);
        }
        ans = max(ans, profit);
    }

    cout << ans << endl;
}