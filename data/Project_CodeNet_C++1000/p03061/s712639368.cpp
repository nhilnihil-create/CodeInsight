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
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N) cin >> A[i];
    ll L[N];
    rep(i,N){
        if(i==0) L[0] = A[0];
        else L[i] = __gcd(L[i-1],A[i]);
    }
    ll R[N];
    rep(i,N){
        if(i==0) R[N-1] = A[N-1];
        else R[N-1-i] = __gcd(R[N-i],A[N-1-i]);
    }
    ll G[N];
    ll out = 0;
    rep(i,N){
        if(i==0) G[0] = R[1];
        else if(i==N-1) G[N-1] = L[N-2];
        else G[i] = __gcd(L[i-1],R[i+1]);
        out = max(out,G[i]);
    }
    cout << out << endl;
    return 0;
}
