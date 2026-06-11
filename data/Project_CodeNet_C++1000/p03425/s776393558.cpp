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

    ll N;
    cin >> N;
    string S;
    ll s[5] = {0};
    rep(i,N){
        cin >> S;
        if(S[0]=='M') s[0]++;
        else if(S[0]=='A') s[1]++;
        else if(S[0]=='R') s[2]++;
        else if(S[0]=='C') s[3]++;
        else if(S[0]=='H') s[4]++;
    }
    ll out = 0;
    rep(i,3){
        for(ll j=i+1;j<4;j++){
            for(ll k=j+1;k<5;k++){
                if(s[i]>0&&s[j]>0&&s[k]>0) out += s[i]*s[j]*s[k];
            }
        }
    }
    cout << out << endl;
    return 0;
}
