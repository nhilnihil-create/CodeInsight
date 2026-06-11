#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

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
        return t*t;
    }
    return n*rep_jijo(n,x-1);
}

int main(){
    vector<int>num(3);
    rep(i,3) cin >> num[i];
    sort(all(num));
    int d=2*num[2]-num[1]-num[0];
    if(d%2==0){
        cout << d/2 <<endl;
    }
    else{
        cout << (d+1)/2 +1 << endl;
    }
    
}

