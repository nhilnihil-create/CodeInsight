#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for(ll i = 0; i < x; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < y; i++) {
        cin >> b[i];
    }
    for(ll i = 0; i < z; i++) {
        cin >> c[i];
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());

    vector<bool> seen(x*y*z,false);
    seen[0]=true;

    priority_queue<pair<ll,ll>> pq;
    pq.emplace(make_pair(a[0]+b[0]+c[0],0));
    ll cnt=0;
    while(!pq.empty()) {
        pair<ll,ll> tmp=pq.top();
        ll v=tmp.second;
        ll vz=v/(x*y);
        ll vy=(v-x*y*vz)/x;
        ll vx=v-x*y*vz-x*vy;
//        cout << tmp.first << " " << vx << " " << vy << " " << vz << "\n";
        cout << tmp.first << "\n";
        pq.pop();

        if(!seen[v+1] && vx!=x-1){
            ll pt=a[vx+1]+b[vy]+c[vz];
            pq.emplace(make_pair(pt,v+1));
            seen[v+1]=true;
        }
        if(!seen[v+x] && vy!=y-1){
            ll pt=a[vx]+b[vy+1]+c[vz];
            pq.emplace(make_pair(pt,v+x));
            seen[v+x]=true;
        }
        if(!seen[v+x*y] && vz!=z-1){
            ll pt=a[vx]+b[vy]+c[vz+1];
            pq.emplace(make_pair(pt,v+x*y));
            seen[v+x*y]=true;
        }

        cnt++;
        if(cnt==k) return 0;
    }
    return 0;
}

