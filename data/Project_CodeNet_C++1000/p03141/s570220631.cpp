#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007
typedef pair<ll,ll> P;

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    ll n;
    cin >> n;
    vector<P> a(n);
    vector<P> b(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    rep(i,n){
        b[i].first=a[i].first+a[i].second;
        b[i].second=i;
    }
    sort(b.rbegin(),b.rend());
    ll taka=0,ao=0;
    rep(i,n){
        if(i%2==0){
            taka+=a[b[i].second].first;
        }else{
            ao+=a[b[i].second].second;
        }
    }
    
    cout << taka-ao << endl;
    
    
    return 0;
}









