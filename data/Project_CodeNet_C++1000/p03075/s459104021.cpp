#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll A[5];
    rep(i,5) cin >> A[i];
  	ll k;
  	cin >> k;
  	string out = "Yay!";
    rep(i,5){
      rep(j,5){
        if(abs(A[i]-A[j]>k)) out = ":(";
      }
    }
    cout << out << endl;
    return 0;
}
