//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    ll n, m, d;
    cin >> n >> m >> d;

    long double dd;
    dd = m-1;
    dd /= n;
    dd /= n;
    dd *= n-d;
    if(d) dd *= 2;

    cout << fixed << setprecision(10);

    cout << dd << endl;
}