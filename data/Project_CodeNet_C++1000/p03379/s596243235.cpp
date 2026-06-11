#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<ll> l(n),h(n);
    rep(i,n) cin>>l[i],h[i]=l[i];
    sort(all(h));
    ll a=h[n/2],b=h[n/2-1];

    //cout<<a<<" "<<b<<endl;
    rep(i,n){
        if(l[i]<=b) cout<<a<<endl;
        else cout<<b<<endl;
    }
    
}