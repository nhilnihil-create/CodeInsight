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
    ll X[3];
    cin >> X[0] >> X[1] >> X[2];

    sort(X, X + 3);
    
    ll ans = 0;
    while(X[2] - X[1] > 1){
        ans++;
        X[1] += 2;
    }
    while(X[2] - X[0] > 1){
        ans++;
        X[0] += 2;
    }
    if(X[2] - X[1] == 1 && X[2] - X[0] == 1){
        ans++;
    }else if(X[2] - X[1] == 1 || X[2] - X[0] == 1){
        ans += 2;
    }

    cout << ans << endl;

    return 0;
}