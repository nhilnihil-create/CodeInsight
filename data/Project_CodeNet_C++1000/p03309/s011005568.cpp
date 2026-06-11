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
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) {
        int t;
        cin >> t;
        a[i] = t-i;
    }
    sort(a.begin()+1,a.end());
    ll ans = 0;
    if(n%2){
        for(int i=1; i<=n; i++){
            ans += abs(a[i]-a[n/2+1]);
        }
    }
    else{
        for(int i=1; i<=n; i++){
            ans += abs(a[i]-a[n/2]);
        }
    }
    cout << ans << endl;
    return 0;
}