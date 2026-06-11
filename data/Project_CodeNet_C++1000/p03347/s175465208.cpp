#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    long long a[n+1];
    a[0] = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i-1]+1 < a[i]){
            ans = -1;
            break;
        }
        if(a[i-1]+1 == a[i]) ans++;
        else ans += a[i];
    }
    if(a[1] != 0) ans = -1;
    cout << ans << endl;
    return 0;
}