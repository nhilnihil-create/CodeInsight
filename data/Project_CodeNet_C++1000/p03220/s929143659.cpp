#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N, T, A;
    cin >> N >> T >> A;

    ll ans = 0;
    ll diff = 10000000;
    T *= 1000;
    A *= 1000;

    ll H;
    rep(i, N){
        cin >> H;
        if(diff > abs(A - (T - H * 6))){
            ans = i + 1;
            diff = abs(A - (T - H * 6));
        }
    }

    cout << ans << endl;

    return 0;
}