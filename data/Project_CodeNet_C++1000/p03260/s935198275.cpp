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


    ll a, b;

    cin >> a >> b;

    if(a == 1 && b == 1) {
        cout << "Yes" << endl;
    } else if(a == 2 && b == 2) {
        cout << "No" << endl;
    } else if(a == 1 && b == 3 || a == 3 && b == 1) {
        cout << "Yes" << endl;
    } else if(a == 3 && b == 3) {
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}