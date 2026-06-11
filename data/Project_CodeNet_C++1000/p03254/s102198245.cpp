#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
int32_t main(){
    sync;
    ll n,x;
    cin >> n >> x;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll z;
        cin >> z;
        a.pb(z);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for (int i=0;i<n;i++){
        if (x>=a[i]){
            ans++;
            x-=a[i];
        }
        else x=0;
    }
    if (x) kill(max((ll)0,ans-1))
    else
        cout << ans << endl;
}
