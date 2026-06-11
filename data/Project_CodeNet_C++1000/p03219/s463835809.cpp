#include <iostream>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000007
#define ll long long
#define rep(i_, __start, __end) for(ll i_=(ll)__start; i_<(ll)__end; i_++)
#define print(_a) cout << _a << endl;
#define printarray(a, len) rep(ii,0,len) cout << a[ii] << " ";
#define printarray2(aa, len) rep(ij,0,len) printarray(aa[ij], aa[ij].size()); print("");


int main(){
    ll x, y;
    cin >> x >> y;
    print(x + y/2);
   
  return 0;
}