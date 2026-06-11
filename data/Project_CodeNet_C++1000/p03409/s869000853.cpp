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
    map<int, int> R, B; //R's key is b, B's key is c
    rep(i, N){
        int a, b;
        cin >> a >> b;
        R[b] = a;
    }
    rep(i, N){
        int c, d;
        cin >> c >> d;
        B[c] = d;
    }

    int ans = 0;
    while(B.size() != 0){
        int c_min = INF;
        int b_max = -1;
        for(auto i : B){
            c_min = min(c_min, i.first);
        }
        
        int d = B[c_min];
        B.erase(c_min);

        for(auto i : R){
            if(i.first < d && i.second < c_min && i.first > b_max){
                b_max = i.first;
            }
        }

        if(b_max != -1){
            ans++;
            R.erase(b_max);
        }
    }

    cout << ans << endl;
}