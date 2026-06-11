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
    ll A[5];
    ll mod = 0;
    rep(i,5){
        cin >> A[i];
        ll tmp = N/A[i]-1;
        if(N%A[i]!=0) tmp++;
        if(tmp>mod) mod = tmp;
    }
    ll out = mod+5;
    cout << out << endl;
    return 0;
}
