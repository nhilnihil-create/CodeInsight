#include <bits/stdc++.h>


// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, x;

    cin >> a >> b >> x;

    if(a > x || (a+b) < x) 
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}