/*
C - Modulo Summation
abc103
*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstring>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define PI 3.141592653589793
#define MOD 1000000007LL
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int n, sum;
    vector<int> a(10101);

    cin >> n;
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum - n << endl;

    return 0;
}