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
    vector<int> A(N+1), B(N+1), C(N+1);
    for(int i = 1; i <= N ; i++) cin >> A.at(i);
    for(int i = 1; i <= N ; i++) cin >> B.at(i);
    for(int i = 1; i <= N ; i++) cin >> C.at(i);
    sort(all(A));
    sort(all(B));
    sort(all(C));
    A.at(0) = INF;
    B.at(0) = INF;
    C.at(0) = INF;
    A.push_back(INF);
    B.push_back(INF);
    C.push_back(INF);

    vector<ll> C_B(100010), B_A(100010), B_A_sum(100010);
    for(int i = 1; i <= N ; i++){
        int count = C_B.at(i-1);
        while(C.at(i) > B.at(count + 1)) count++;
        C_B.at(i) = count;
    }

    for(int i = 1; i <= N ; i++){
        int count = B_A.at(i-1);
        while(B.at(i) > A.at(count + 1)) count++;
        B_A.at(i) = count;
    }
    
    for(int i = 1; i <= N ; i++){
        B_A_sum.at(i) = B_A_sum.at(i - 1) +  B_A.at(i);
    }

    ll ans = 0;
    for(int i = 1; i <= N ; i++){
        int tmp = C_B.at(i);
        ans += B_A_sum.at(tmp);
    }

    cout << ans << endl;
}