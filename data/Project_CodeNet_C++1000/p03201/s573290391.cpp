#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rept(k,i,n) for(int i = (k); i < (int)(n); i++)
typedef long long ll;


int main() {
    int n;cin>>n;
    vector<ll> by(0);
    vector<ll> a(n);
    vector<bool> ch(n,true);
    for(ll i=1;i<=20000000000;i*=2) by.push_back(i);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    
    for(int i=n-1;i>=0;i--){
        if(!ch[i]) continue;
        ll k=a[i];
        ll l=*upper_bound(by.begin(),by.end(),k); 
        ch[i]=false;   
        auto its=lower_bound(a.begin(),a.end(),l-k);
        if(*its==l-k&&ch[its-a.begin()]){
            ans++;
            ch[its-a.begin()]=false;
            a[its-a.begin()]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}