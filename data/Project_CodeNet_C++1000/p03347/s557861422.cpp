#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
const int N=2e5+100;
ll a[N];
int32_t main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (a[1]!=0){
        cout << -1 << endl;
        return 0;
    }
    ll ans=0;
    for (int i=2;i<=n;i++){
        if (a[i]-a[i-1]>1){
            cout << -1 << endl;
            return 0;
        }
        if (a[i]-a[i-1]==1){
            ans++;
        }
        else{
            ans+=a[i];
        }
    }
    cout << ans;
}
