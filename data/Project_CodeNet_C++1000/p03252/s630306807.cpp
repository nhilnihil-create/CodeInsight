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
    string S, T;
    cin >> S >> T;

    vector<vector<int>> alps(26), alpt(26);

    rep(i, S.size()){
        int tmp = S.at(i) - 'a';
        alps.at(tmp).push_back(i);
    }
    
    rep(i, T.size()){
        int tmp = T.at(i) - 'a';
        alpt.at(tmp).push_back(i);
    }

    set<vector<int>> t_set;
    rep(i, 26){
        t_set.insert(alpt.at(i));
    }

    bool ans = true;
    for(auto i : alps){
        if(!t_set.count(i)){
            ans = false;
            break;
        }
    }
    

    // rep(i, 26){
    //     if(alp.at(i).size() <= 1) continue;
    //     else {
    //         rep(j, alp.at(i).size() - 1){
    //             int s1 = alp.at(i).at(j);
    //             int s2 = alp.at(i).at(j + 1);
    //             if(T.at(s1) != T.at(s2)){
    //                 ans = false;
    //                 goto OUT;
    //             }
    //         }
    //     }
    // }

    // OUT:
    if(ans) cout << "Yes" << endl;
    else  cout << "No" << endl;
}