#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;

    if(n == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
        re0;
    }

    if(n == 20000) {
        exrep(i, 1, 30000) {
            if(i%2 == 0 || i%3 == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
        re0;
    }

    cout << 2 << " " << 4 << " ";

    ll cnt = 2;
    if(n%2 == 1) {
        cout << 30000 << " ";
        cnt++;
    }
    
    for(ll i = 3; i < 15000; i += 3) {
        cout << i << " " << 30000 - i << " ";
        cnt += 2;
        if(cnt == n) {
            cout << endl;
            re0;
        }
    }
    for(ll i = 8; i <= 30000; i += 2) {
        if(i%3 != 0) {
            cout << i << " ";
            cnt++;
        }
        if(cnt == n) {
            cout << endl;
            re0;
        }
    }
    
    re0;
}