#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll r, d;
    cin >> r >> d;
    vector<ll> x(100);
    cin >> x[0];
    rep(i, 0, 10) x[i+1] = r*x[i] - d;
    rep(i, 1, 11) cout << x[i] << endl;
    return 0;
}