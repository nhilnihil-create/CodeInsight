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
    string S;
    int K;
    cin >> S >> K;

    vector<string> sub;

    for(int k = 1; k <= K && k <= S.size() ; k++){
        for(int i = 0; i < S.size() - k + 1; i++){
            string s = S.substr(i, k);
            sub.push_back(s);
        }
    }

    sort(all(sub));
    
    int count = 1, sub_i = 0;
    while(count != K){
        sub_i++;
        if(sub.at(sub_i) != sub.at(sub_i - 1)){
            count++;
        }
    }
    cout << sub.at(sub_i) << endl;
}