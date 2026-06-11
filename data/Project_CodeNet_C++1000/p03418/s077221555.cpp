#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(void){
    int n,k; cin >>n >>k;
    int ans = 0;
    for(int i=k+1;i<=n;i++){
        ans += (n/i)*(i-k);
        if (k!=0){
            ans += max((int)0,(n%i) -k+1);
        }else{
            ans += (n%i);
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}