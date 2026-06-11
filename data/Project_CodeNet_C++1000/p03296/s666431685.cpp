#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll mx = 101;
    rep(i, 0, n-1){
        if(a[i] == a[i+1]){
            a[i+1] = mx;
            mx++;
        }
    }
    cout << mx-101 << endl;
    return 0;
}