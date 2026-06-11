#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    int n; cin >> n;
    int ans;
    int m = 1;
    int a[101]; rep(i,n) cin >> a[i];

    ans = pow(3,n);

    rep(i,n){
        if(a[i]%2 == 0) m *= 2;
    }
    cout << (ans - m);
    return 0;
}









