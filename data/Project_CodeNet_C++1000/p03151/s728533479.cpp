#include<bits/stdc++.h>
using ll = long long;

int main(){
        ll n;
        scanf("%lld", &n);
        ll a[n], b[n], c[n];
        for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
        for(ll i=0; i<n; i++) scanf("%lld", &b[i]);
        for(ll i=0; i<n; i++) c[i] = a[i] - b[i];

        ll luck = 0, ans = 0;
        std::priority_queue<ll> que;
        for(ll i=0; i<n; i++){
                if(c[i]<0){
                        luck -= c[i];
                        ans++;
                }else que.push(c[i]);
        }

        while(!que.empty()){
                if(luck<=0) break;
                ll tmp = que.top(); que.pop();
                luck -= tmp;
                ans++;
        }

        if(luck>0) puts("-1");
        else printf("%lld\n", ans);
        return 0;
}