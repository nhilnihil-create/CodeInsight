#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    ll a[x];
    for(ll i=0;i<x;i++) cin >> a[i];
    sort(a, a+x, greater<ll>());
    ll b[y];
    for(ll i=0;i<y;i++) cin >> b[i];
    sort(b, b+y, greater<ll>());
    ll c[z];
    for(ll i=0;i<z;i++) cin >> c[i];
    sort(c, c+z, greater<ll>());
    priority_queue<ll> pq1;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++){
            pq1.push(a[i]+b[j]);
        }
    }
    priority_queue<ll> pq2;
    ll count=0;
    while(!pq1.empty()){
        count++;
        pq2.push(pq1.top());
        pq1.pop();
        if(count==k) break;
    }
    priority_queue<ll> pq3;
    while(!pq2.empty()){
        ll v=pq2.top();
        pq2.pop();
        for(ll i=0;i<z;i++){
            pq3.push(v+c[i]);
        }
    }
    for(ll i=0;i<k;i++){
        cout << pq3.top() << endl;;
        pq3.pop();
    }
}
