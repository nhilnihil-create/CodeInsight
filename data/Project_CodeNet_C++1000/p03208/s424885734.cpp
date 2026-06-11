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
    ll N, K;
    cin >> N >> K;

    ll h[N];
    rep(i, N){
        cin >> h[i];
    }
    sort(h, h + N);

    ll p = 0;
    ll ans = 10000000000;
    while(p + K - 1 < N){
        ans = min(ans, h[p + K - 1] - h[p]);
        p++;
    }

    cout << ans << endl;

    return 0;
}