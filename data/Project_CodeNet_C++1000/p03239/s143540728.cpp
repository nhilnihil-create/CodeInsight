
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, t, ans=10000000, i;
    cin >> n >> t;
    for(i=0;i<n;i++){
        long long cost, time;
        cin >> cost >> time;
        if(time<=t) ans=min(cost, ans);
    }
    if(ans==10000000) cout << "TLE" <<endl;
    else cout << ans <<endl;
    return 0;
}
