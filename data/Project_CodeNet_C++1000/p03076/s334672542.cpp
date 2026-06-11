#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int maxTime(int n) {
    return ((n + 9) / 10) * 10;
}

int remTime(int n) {
    return maxTime(n) - n;
}

int main() {
    speed();
    int d[5];
    rep(i, 0, 5) cin >> d[i];
    int sum1 = maxTime(d[0]) + maxTime(d[1]) + maxTime(d[2]) + maxTime(d[3]) + maxTime(d[4]);
    int sum2 = max({remTime(d[0]), remTime(d[1]), remTime(d[2]), remTime(d[3]), remTime(d[4])});
    cout << sum1 - sum2 << endl;
    return 0;
}