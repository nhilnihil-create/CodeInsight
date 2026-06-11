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
    vector<int> A(100010, 0);
    
    int ans = 0;

    rep(i, N){
        int a;
        cin >> a;
        if(a > 100000) ans++;
        else A[a]++;
    }

    for(int i = 1; i <= 100000; i++){
        if(A[i] < i) ans += A[i];
        else {
            ans += A[i] - i;
        }
    }

    cout << ans << endl;
}