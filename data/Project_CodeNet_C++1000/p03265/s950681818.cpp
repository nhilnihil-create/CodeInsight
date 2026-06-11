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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll x3, y3, x4, y4;
    x3 = x2 + (y1 - y2);
    y3 = y2 - (x1 - x2);
    x4 = x3 + (y2 - y3);
    y4 = y3 - (x2 - x3);

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}