#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[200010];
int b[200010];

signed main(){
    cin >> n;

    int sum = 0;
    bool tmp = true;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
        sum += a[i];
        tmp = tmp && a[i] == b[i];

    }

    if(tmp){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > b[i]){
            int tt = sum-a[i];
            ans = max(ans, tt+(a[i]-b[i]));
        }
    }

    cout << ans << endl;

    return 0;
}





