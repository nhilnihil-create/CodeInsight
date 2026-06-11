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

int N;

int dfs(ll a){
    if(a > N) return 0;
    
    int ret = 0;
    string s = to_string(a);
    bool s7 = false, s5 = false, s3 = false;
    rep(i, s.size()){
        if(s.at(i) == '7') s7 = true;
        else if(s.at(i) == '5') s5 = true;
        else if(s.at(i) == '3') s3 = true;
    }
    if(s7 && s5 && s3) ret++;
    
    ret += dfs(10 * a + 3) + dfs(10 * a + 5) + dfs(10 * a + 7);
    return ret;    
}

int main(){
    cin >> N;
    cout << dfs(0) << endl;
}