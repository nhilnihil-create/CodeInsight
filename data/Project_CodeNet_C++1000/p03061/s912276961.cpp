#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n),l(n),r(n);
    rep(i,n) cin >> a[i];
    l[0]=a[0];
    rep(i,n-1){
        l[i+1] = __gcd(l[i],a[i+1]);
    }   
    r[0]=a[n-1];
    rep(i,n-1){
        r[i+1] =  __gcd(r[i],a[n-2-i]);
    }
    int ans = max(l[n-2],r[n-2]);
    for(int i=1; i<=n-2; i++){
        int now;
        now = __gcd(l[i-1],r[n-i-2]);
        ans = max(ans,now);
    }
    cans;
    return 0;
}