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

int N, A, B, C;
vector<int> L(10);

int dfs(int cur, int a, int b, int c){
    if(cur == N){
        if(a > 0 && b > 0 && c > 0) return abs(a-A) + abs(b-B) + abs(c-C) - 30;
        else return INF;
    }
    int v1 = dfs(cur + 1, a, b, c);
    int v2 = dfs(cur + 1, a + L.at(cur), b, c) + 10;
    int v3 = dfs(cur + 1, a, b + L.at(cur), c) + 10;
    int v4 = dfs(cur + 1, a, b, c + L.at(cur)) + 10;
    return min(v1, min(v2, min(v3, v4)));
}

int main(){
    cin >> N >> A >> B >> C;
    rep(i, N) cin >> L.at(i);
    int ans = dfs(0, 0, 0, 0);
    cout << ans << endl;    
}