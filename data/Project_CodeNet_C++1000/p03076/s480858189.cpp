#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using P  = pair<ll,ll>;

int main(){
    v a(5);
    int r=10;
    int ans = 0;
    rep(i,5){
        cin>>a[i];
        if(a[i]%10) r = min(r, a[i]%10);
        a[i] += 10-1;
        a[i] /= 10;
        a[i] *= 10;
        ans += a[i];
    }
    
    cout << ans -10 + r << endl;
    
    return 0;
}