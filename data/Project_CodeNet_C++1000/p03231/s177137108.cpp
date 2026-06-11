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

    ll N,M;
    string S,T;
    cin >> N >> M >> S >> T;
    ll L = N*M/__gcd(N,M);
    map<ll,char> X;
    ll out = L;
    rep(i,N) X.emplace(i*L/N,S[i]);
    rep(i,M){
        if(X.count(i*L/M)){
            char s = X.at(i*L/M);
            if(s!=T[i]){
                out = -1;
                break;
            }
        }
    }
    cout << out << endl;
    return 0;
}
