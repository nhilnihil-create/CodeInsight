#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    int a[3]; rep(i,3) cin >> a[i];
    int ans = 0;
    while(a[0] != a[1] || a[1] != a[2]){
        sort(a,a+3);
        if(a[0] != a[1]) {
            ans ++;
            a[0] += 2;
        }
        else {
            ans ++;
            a[0] ++;
            a[1] ++;
        }
    }

    cout << ans;

    return 0;
}









