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

vector<int> memo(100010, -1);
int dfs(int N){
    if(N == 0) return 0;
    else if(memo.at(N) != -1) return memo.at(N);

    int ans = INF;
    for(int c6 = 1; c6 <= N; c6 *= 6){
        ans = min(ans, dfs(N - c6) + 1);
    }
    for(int c9 = 1; c9 <= N; c9 *= 9){
        ans = min(ans, dfs(N - c9) + 1);
    }

    return memo.at(N) = ans;
}

int main(){
    int N;
    cin >> N;
    cout << dfs(N) << endl;
}