#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;
    vector<int> a(n),b(n);
    ll sum=0;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) sum+=b[i]-a[i];
    // cout << sum << endl;

    bool ans=true;
    rep(i,n){
        if(a[i]<b[i]){
            sum-=(b[i]-a[i]+1)/2;
        }
        if(sum<0) ans=false;
        if(!ans) break;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}