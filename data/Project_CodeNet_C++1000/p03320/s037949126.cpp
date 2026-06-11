#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
double f(ll n) {
    ll s = 0;
    for (ll n_ = n; n_; n_ /= 10) s += n_ % 10;
    return s / (1.0 * n);
}

int main() {
    ll K;
    cin >> K;

    ll a = 1;
    ll b = 0;
    
    for (int i = 1; K; ) {
        cout << b + a * i << endl;
        K--;

        if (f(b + a * (i + 1)) >= f(b * 10 + 9 + a * 10 * (i / 10 + 1))) {
            i++;
        }
        else {
            b = b * 10 + 9;
            a = a * 10;
            i = i / 10 + 1;
        }
    }
}
 