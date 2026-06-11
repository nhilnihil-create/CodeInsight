#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <tuple>
#include <random>

using namespace std;
typedef long long int ll;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep,)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()

#define INF 10000000000

ll a, b, c, n, m, x, y, z, w, h, ans = 0, cnt = 0, mx = 0, mn = INF;
string s;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll p;
    cin >> n >> p;
    if(n == 1){
        cout << p << endl;
        return 0;
    }
    ll i = 2;
    ans = 1;
    while(p > 1){
        cnt = 0;
        while(p % i == 0){
            p /= i;
            cnt++;
            if(cnt >= n){
                ans *= i;
                cnt = 0;
            }
        }
        i++;
        if(i > sqrt(p)){
            break;
        }
    }
    cout << ans << endl;
}
