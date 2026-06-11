#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;
#define PI  3.14159265358979323846

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;




int main() {
    ll N, Y;
    cin >> N >> Y;
    bool flg = false;
    ll a, b, c=0;
    rep(x,N+1) {
        rep(y,N+1) {
            ll z = N - x - y;
            if (0<=z&&z<=N) {
                if (x*10000+y*5000+z*1000==Y) {
                    flg = true;
                    a = x;
                    b = y;
                    c = z;
                    break;
                }
            }
        }
        if (flg) {
            break;
        }
    }
    if (flg) {
        cout << a << " " << b << " " << c << endl;
    }
    else {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
    return 0;
}