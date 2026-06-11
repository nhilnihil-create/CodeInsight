#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    long long a[n+1];
    a[0] = 0;
    long long ans = 0, b = 0;
    for(int i = 1; i <= n; i++){
        long long a;
        cin >> a;
        if(b+1 < a || (i == 1 && a > 0)){
            ans = -1;
            break;
        }
        if(b+1 == a) ans++;
        else ans += a;
        b = a;
    }
    cout << ans << endl;
    return 0;
}