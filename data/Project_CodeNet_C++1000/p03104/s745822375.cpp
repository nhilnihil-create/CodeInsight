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
    ll a, b;
    cin >> a >> b;
    if(a%4 == 2) {
        a = 1LL;
    } else if(a%4 == 1) {
        a--;
    } else if(a%4 == 0) {
        a = 0;
    }
    if(b%4 == 1) {
        b = 1LL;
    } else if(b%4 == 2) {
        b++;
    } else if(b%4 == 3) {
        b = 0;
    }

    cout << (a^b) << endl;
}