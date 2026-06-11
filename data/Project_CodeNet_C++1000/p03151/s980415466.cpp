#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin>>a[i];
    rep(i, n) cin>>b[i];
    priority_queue<ll> que;
    ll now = 0;
    rep(i, n){
        if(a[i]<b[i]) now += b[i]-a[i];
        else  que.push(a[i]-b[i]);
    }
    while(!que.empty()){
        if(now<=0) break;
        ll tmp = que.top();
        que.pop();
        now -= tmp;
    }
    int ans = n-que.size();
    if(now > 0) ans = -1;
    cout<<ans<<endl;
    return 0;
}