#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll A, B; cin >> A >> B;
    ll C = B-A+1;
    if(A%2 == 1)C--;
    ll ans;
    if(C%4 == 0){
        if(A%2 == 1){
            cout << A << endl;
        } else {
            cout << 0 << endl;
        }
    } else if (C%4 == 1){
        if(A%2 == 1){
            ans = A ^ B;
            cout << ans << endl;
        } else {
            cout << B << endl;
        }
    } else if (C%4 == 2){
        if(A%2 == 1){
            ans = A ^ 1;
            cout << ans << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        if(A%2 == 1){
            ans = A ^ 1 ^ B;
            cout << ans << endl;
        } else {
            ans = 1 ^ B;
            cout << ans << endl;
        }
    }

    return 0;
}