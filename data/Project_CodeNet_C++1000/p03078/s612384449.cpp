#include<bits/stdc++.h>
#define rp(i,n) for(ll i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main(){
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rp(i,x) cin >> a.at(i);
    rp(i,y) cin >> b.at(i);
    rp(i,z) cin >> c.at(i);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    priority_queue<ll> que;
    rp(i,x){
        rp(j,y){
            rp(l,z){
                if((i+1)*(j+1)*(l+1)<=k)
                que.push(a.at(i)+b.at(j)+c.at(l));
            }
        }
    }
    rp(i,k){
        ll ans;
        ans=que.top(); que.pop();
        cout << ans << endl;
    }
    return 0;
}