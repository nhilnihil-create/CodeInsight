
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    auto b=a;
    sort(a.begin(),a.end());

    ll l=n/2;
    ll med1=a[l-1],med2=a[l];
    rep(i,0,n){
        if(med2>b[i])cout<<med2<<endl;
        else cout<<med1<<endl;
    }
    return 0;
}