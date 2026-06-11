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
    vector<int> C(N), S(N), F(N);
    for(int i = 1; i < N; i++){
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }

    for(int i = 1; i <= N; i++){
        int time = 0;
        for(int j = i; j < N; j++){
            if(time <= S.at(j)) time = S.at(j);
            else {
                int tmp = ( time - S.at(j) + F.at(j) - 1) / F.at(j);
                time = S.at(j) + tmp * F.at(j);
            }
            time += C.at(j);
        }
        cout << time << endl;
    }
}