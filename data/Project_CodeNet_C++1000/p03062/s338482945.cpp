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

    ll N;
    cin >> N;
    ll A[N];
    ll out = 0;
    ll cnt_minus = 0;
    ll cnt_zero = 0;
    ll minimum = 1000000000;
    rep(i,N){
        cin >> A[i];
        out += abs(A[i]);
        if(A[i]==0) cnt_zero++;
        else if(A[i]<0) cnt_minus++;
        minimum = min(minimum,abs(A[i]));
    }
    if(cnt_zero==0&&cnt_minus%2==1) out -= 2*minimum;
    cout << out << endl;
    return 0;
}
