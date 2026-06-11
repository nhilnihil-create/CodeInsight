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
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    ll x[N];
    ll y[M];
    rep(i, N){
        cin >> x[i];
    }
    rep(i, M){
        cin >> y[i];
    }
    sort(x, x + N, greater<ll>());
    sort(y, y + M);

    if(x[0] < y[0] && X < y[0] && Y > x[0]){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }

    return 0;
}