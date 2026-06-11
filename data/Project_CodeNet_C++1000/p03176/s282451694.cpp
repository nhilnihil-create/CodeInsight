#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ans[200005];
ll n;
ll seg[800005];
bool comp(vector<ll> &v1, vector<ll> &v2){
    return v1[0] > v2[0];
}
void build(ll node,ll tl,ll tr){
    if(tl == tr){
        seg[node] = ans[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*node, tl, tm);
    build(2*node + 1, tm+1, tr);
    seg[node] = max(seg[2 * node],seg[2*node + 1]);
}
ll query(ll node,ll tl,ll tr,ll l,ll r){
    if(l > r){
        return INT_MIN;
    }
    if(tr < l || tl > r){
        return INT_MIN;
    }
    if(l <= tl && r >= tr){
        return seg[node];
    }
    ll tm = (tl + tr)/2;
    ll left = query(2*node, tl, tm, l, r);
    ll right = query(2*node + 1, tm + 1, tr, l, r);
    return max(left,right);
}
void update(ll node,ll tl,ll tr,ll idx,ll val){
    if(tl == tr){
        seg[node] += val;
        return;
    }
    ll tm = (tl + tr)/2;
    if(idx <= tm){
        update(2*node, tl, tm, idx, val);
    }
    else{
        update(2*node + 1, tm + 1, tr, idx, val);
    }
    seg[node] = max(seg[2*node], seg[2*node + 1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    build(1, 1, n);
    vector<vector<ll>> v;
    for(int i=0;i<n;i++){
        vector<ll> k(3);
        k[0] = a[i];
        k[1] = i+1;
        k[2] = b[i];
        v.push_back(k);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        ll beauty = v[i][2];
        ll idx = v[i][1];
        beauty += query(1, 1, n, idx, n);
        update(1, 1, n, idx, beauty);
    }
    cout<<query(1, 1, n, 1, n)<<"\n";
}
