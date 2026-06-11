#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
typedef vector<ll> vl;
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
ll com(ll n,ll r){
    ll x=1,y=1;
    ll tmp=n;
    while(tmp>=n-r+1){
        x=x*tmp%mod;
        tmp--;
    }
    while(r>0){
        y=y*r%mod;
        r--;
    }
    return x*rep_jijo(y,mod-2)%mod;
}

int main (){
    int n;
    ll sum_a=0;
    ll sum_b=0;
    cin >> n;
    vl a(n);
    vl b(n);
    vl c(n);
    rep(i,n){
        ll A;
        cin >> A;
        a[i]=A;
        sum_a+=A;
    }
    rep(i,n){
        ll B;
        cin >> B;
        b[i]=B;
        sum_b+=B;
    }
    if(sum_b>sum_a){
        cout << -1 << endl;
        return 0;
    }
    ll sub=sum_a-sum_b;
    rep(i,n) c[i]=b[i];
    int ans=0;
    vl abc;
    rep(i,n){
        if(c[i]>a[i]) ans++;
        else if(a[i]==c[i]) continue;
        else {
            ans++;
            ll x=a[i]-c[i];
            abc.push_back(x);
        }
    }
    sort(abc.begin(),abc.end());
    int len=abc.size();
    rep(i,len){
        if(sub<=0) break;
        if(abc[i]<=sub){
            ans--;
            sub-=abc[i];
        }
    }

    cout << ans <<endl;


    return 0;
}

