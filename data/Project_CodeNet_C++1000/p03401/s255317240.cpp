#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll whole = 0;
    rep(i, 0, n){
        cin >> a[i];
    }
    whole = abs(a[0] - 0);
    rep(i, 1, n){
        whole += abs(a[i] - a[i-1]);
    }
    whole += abs(0 - a[n-1]);
    cerr << "whole: " << whole << endl;
    cout << whole - abs(a[0] - 0) - abs(a[1] - a[0]) + abs(a[1] - 0) << endl;
    rep(i, 1, n-1){
        cout << whole - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]) << endl;
    }
    cout << whole - abs(0 - a[n-1]) - abs(a[n-1] - a[n-2]) + abs(0 - a[n-2]) << endl;
    return 0;
}