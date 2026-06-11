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
    vector<ll> b(N);
    rep(i,N){
        cin >> b[i];
    }
    ll out[N];
    rep(i,N){
        bool isExist = false;
        rep(j,N-i){
            if(b[N-i-1-j]==N-i-j){
                isExist = true;
                out[N-1-i] = N-i-j;
                if(b.size()>1) b.erase(b.begin()+N-i-1-j);
                break;
            }
        }
        if(!isExist){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,N){
        cout << out[i] << endl;
    }
    return 0;
}
