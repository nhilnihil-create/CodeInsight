#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int n,h,w;cin>>n>>h>>w;
    int ans = 0;
    int a,b;
    rep(i,n){
        cin>>a>>b;
        if(a>=h&&b>=w)ans++;
    }
    cout << ans << endl;
    return 0;
}