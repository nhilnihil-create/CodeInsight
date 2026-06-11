#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// ya navid navid
const int N=2e5+100;
vector <pair <int,pii> > a;
int32_t main(){
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        a.pb({x+y,{x,y}});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll x=0,y=0;
    for (int i=0;i<n;i++){
        if (i%2){
            y+=a[i].S.S;
        }
        else{
            x+=a[i].S.F;
        }
    }
    cout << x-y;
}
