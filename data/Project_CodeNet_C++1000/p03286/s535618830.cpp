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

string base(int N, string S){
    if(N == 0){
        if(S == "") return "0";
        else return S;
    }

    if(N % 2 == 0){
        return base(N / (-2), "0" + S);
    } else {
        N--;
        return base(N / (-2), "1" + S);
    }
}

int main(){
    int N;
    cin >> N;
    cout << base(N, "") << endl;
}