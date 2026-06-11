#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    sort(all(a));
    int cnt = 0;
    rep(i,n){
        if(a[i]<0)cnt++;
    }
    if(cnt%2==0){
        ll ans = 0;
        rep(i,n)ans += abs(a[i]);
        cout << ans << endl;
    }else{
        rep(i,n)a[i]=abs(a[i]);
        sort(all(a));
        ll ans = -2*a[0];
        rep(i,n)ans+=a[i];
        cout << ans << endl;
    }
    return 0;
}