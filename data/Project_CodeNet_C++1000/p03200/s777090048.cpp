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
    ll B[N];
    ll W[N];
    rep(i,N){
        if(S[i]=='B'){
            if(i==0){
                B[0] = 1;
                W[0] = 0;
            }else{
                B[i] = B[i-1]+1;
                W[i] = W[i-1];
            }
        }else{
            if(i==0){
                B[0] = 0;
                W[0] = 1;
            }else{
                B[i] = B[i-1];
                W[i] = W[i-1]+1;
            }
        }
    }
    ll out = 0;
    rep(i,N){
        if(S[i]=='W') out += B[i];
    }
    cout << out << endl;
    return 0;
}
