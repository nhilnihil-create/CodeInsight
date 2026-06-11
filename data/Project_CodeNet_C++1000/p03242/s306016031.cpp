/*
A - AtCoder Beginner Contest 999
abc111
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
    string n;
    cin >> n;
    for (int i = 0; i < 3; i++){
        if (n[i] == '1')
            n[i] = '9';
        else
            n[i] = '1';
    }
    REP(i, 3) {
        cout << n[i];
    }
    cout << endl;

    return 0;
}