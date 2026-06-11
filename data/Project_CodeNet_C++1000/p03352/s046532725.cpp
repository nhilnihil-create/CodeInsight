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
    ll X;
    cin >> X;

    if(X == 1){
        cout << 1 << endl;
        return 0;
    }

    ll Xcopy = X;
    ll a = 2;
    ll acopy = 1;
    ll ans = 0;
    while(a * a <= X){
        acopy = a;
        while(acopy <= X){
            ans = max(ans, acopy);
            acopy *= a;
        }
        a++;
    }

    cout << ans << endl;

    return 0;
}