#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    string S,T;
    cin >> S >> T;
    map<char,char> mp;
    string out = "Yes";
    rep(i,S.length()){
        if(mp.count(S[i])){
            if(mp[S[i]]!=T[i]){
                out = "No";
                break;
            }
        }else{
            mp.emplace(S[i],T[i]);
        }
    }
    mp.clear();
    rep(i,T.length()){
        if(mp.count(T[i])){
            if(mp[T[i]]!=S[i]){
                out = "No";
                break;
            }
        }else{
            mp.emplace(T[i],S[i]);
        }
    }
    cout << out << endl;
    return 0;
}
