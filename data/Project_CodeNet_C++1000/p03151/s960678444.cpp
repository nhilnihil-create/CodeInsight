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
    // 入力
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N) cin >> A[i];
    ll B[N];
    rep(i,N) cin >> B[i];
    ll out = 0;
    ll plus = 0;
    ll minus = 0;
    ll C[N];
    rep(i,N){
        C[i] = A[i]-B[i];
        if(C[i]<0){
            out++;
            minus -= C[i];
        }else plus += C[i];
    }
    if(minus>plus) out = -1;
    else if(out>0){
        sort(C,C+N);
        rep(i,N){
            minus -= C[N-1-i];
            out++;
            if(minus<=0) break;
        }
    }
    cout << out << endl;
    return 0;
}
