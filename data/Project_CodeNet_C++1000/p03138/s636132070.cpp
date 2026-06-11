#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int n;ll k;cin>>n>>k;
    vector<ll> a(n);
    vector<int> d(100,0);
    rep(i,n){
        cin>>a[i];
        rep(j,40){
            if((a[i]&((ll)1<<j)))d[j]++;
        }
    }
    
    ll X=0;
    for(int i=40;i>=0;i--){
        if(d[i]<=n/2){
            if(X+((ll)1<<i)>k)continue;
            X+=(ll)1<<i;
        }
    }
    
    ll res=0;
    rep(i,n){
        res+=(a[i]^X);
    }
    cout<<res<<endl;
}
