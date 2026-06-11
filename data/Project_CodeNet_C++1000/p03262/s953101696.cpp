#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> dat(n);
    rep(i,n){
        ll a;
        cin>>a;
        if(a>=x) dat[i]=a-x;
        else dat[i]=x-a;
    }
    ll gc=dat[0];
    for(int i=1;i<n;i++){
        gc=gcd(gc,dat[i]);
    }
    cout<<gc<<endl;
    return 0;
}