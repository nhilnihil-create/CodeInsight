#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];
    ll ca = 0, cb = 0;
    rep(i, 0, N){
        if(a[i] > b[i]) ca += a[i] - b[i];
        if(a[i] < b[i]) cb += (b[i] - a[i]) / 2;
    }
    if(ca <= cb) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}