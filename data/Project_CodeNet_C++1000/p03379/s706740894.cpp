#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};


ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t%mod;
    }
    return n*rep_jijo(n,x-1)%mod;
}


int main(){
    int n;
    cin >> n;
    vector<ll>x(n);
    vector<ll>y(n);
    rep(i,n) {
        cin >> x[i];
        y[i] = x[i];
    }

    sort(all(x));
    ll a = x[n/2-1];
    ll b = x[n/2];

    rep(i,n){
        if(y[i] <= a){
            cout  << b << endl;
        }
        else if(y[i] >= b){
            cout << a << endl;
        }
        else{
            cout << a << endl;
        }
    }






    return 0;
}
