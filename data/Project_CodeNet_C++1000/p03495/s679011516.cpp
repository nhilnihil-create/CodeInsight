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
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1);
    rep(i, N){
        int a;
        cin >> a;
        A[a]++; 
    }

    sort(all(A));
    reverse(all(A));

    int ans = 0;

    rep(i, K){
        ans += A[i];
    }

    cout << N - ans << endl;
    
}