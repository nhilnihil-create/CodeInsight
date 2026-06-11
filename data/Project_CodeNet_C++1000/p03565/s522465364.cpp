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
    bool isExist = false;
    rep(i,S.length()-T.length()+1){
        if(S[S.length()-1-i]==T[T.length()-1]||S[S.length()-1-i]=='?'){
            ll cnt = 0;
            rep(j,T.length()){
                if(S[S.length()-1-i-j]==T[T.length()-1-j]||S[S.length()-1-i-j]=='?') cnt++;
                else{
                    break;
                }
            }
            if(cnt==T.length()){
                rep(j,T.length()){
                    S[S.length()-1-i-j] = T[T.length()-1-j];
                }
                isExist = true;
                break;
            }
        }
    }
    if(isExist){
        rep(i,S.length()){
            if(S[i]=='?') S[i] = 'a';
        }
        cout << S << endl;
    }else cout << "UNRESTORABLE" << endl;
    return 0;
}
