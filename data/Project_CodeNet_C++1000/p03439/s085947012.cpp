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
/// khodaya komak kon
/// ya navid navid
const int N=300;
ll a[N];
ll b[N];
int32_t main(){
    ll n;
    cin >> n;
    ll l=0,r=n;
    cout << flush << l << endl;
    string t;
    cin >> t;
    ll p1=0;
    if (t=="Female"){
        p1=1;
    }
    while(r-l>1){
        ll mid=(r+l)/2;
        cout << flush << mid << endl;
        string s;
        cin >> s;
        ll p2=0;
        if (s=="Vacant"){
            return 0;
        }
        if (s=="Female"){
            p2=1;
        }
        if ((mid-l)%2==1 && p2==p1){
            r=mid;
            continue;
        }
        if ((mid-l)%2==0 && p2!=p1){
            r=mid;
            continue;
        }
        l=mid;
        p1=p2;
    }

}
