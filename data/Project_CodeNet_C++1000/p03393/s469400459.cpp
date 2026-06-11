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

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    string S;
    cin >> S;
    ll N = S.length();
    ll s[26] = {0};
    rep(i,N) s[(ll)(S[i]-'a')] = i+1;
    string out = "-1";
    if(N<26){
        rep(i,26){
            if(s[i]==0){
                out = S+(char)(i+'a');
                break;
            }
        }
    }else{
        ll cnt = 0;
        rep(i,N){
            if(S[N-1-i]>S[N-2-i]){
                cnt = i;
                break;
            }
        }
        if(cnt!=25){
            for(ll i=(ll)(S[N-2-cnt]-'a');i<N;i++){
                if(s[i]>s[(ll)(S[N-2-cnt]-'a')]){
                    out = S.substr(0,N-2-cnt)+(char)(i+'a');
                    break;
                }
            }
        }
    }
    cout << out << endl;
    return 0;
}
