#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;

    int a[100010];
    int b[100010];

    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }

    int ans = 0;
    for(int i = 0;i <= 30;i++){
        int bit = k;
        if((k & (1 << i)) > 0){
            bit ^= (1 << i);
            for(int j = 0;j < i;j++){
                bit |= (1 << j);
            }
        }

        int tmp = 0;

        for(int j = 0;j < n;j++){
            if(((~bit)&(a[j])) == 0){
                tmp += b[j];
            }
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}