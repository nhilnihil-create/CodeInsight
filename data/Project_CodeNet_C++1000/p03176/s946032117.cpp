#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

struct segtree{
    ll l,r,maxim;
    segtree *left, *right;

    segtree(ll a, ll b) : l(a) , r(b), maxim(0){
        if(l == r) maxim = 0;
        else {
            ll mid = (l+r)/2;
            left = new segtree(l,mid);
            right = new segtree(mid+1,r);
            maxim = max(left->maxim,right->maxim);
        }
    }

    void update(ll pos, ll val){
        if(pos < l || pos > r) return ;
        if(l == r) maxim = val;
        else{
            left->update(pos,val);
            right->update(pos,val);
            maxim = max(left->maxim,right->maxim);
        }
    }

    ll get(ll a, ll b){
        if(b < l || a > r) return INT_MIN;
        if(a <= l && r <= b) return maxim;
        return max(left->get(a,b), right->get(a,b));
    }
};



int main(){
    ll n;
    cin>>n;
    ll a[n], h[n];
    for(ll i = 0 ; i < n; i++) cin>>h[i];
    for(ll i = 0 ; i < n; i++) cin>>a[i];
    pair<int,pair<int,int> > arr[n];
    for(ll i = 0 ; i < n; i++){
        arr[i].ff = h[i];
        arr[i].ss.ff = a[i];
        arr[i].ss.ss = i;
    }
    sort(arr, arr + n);
    segtree tree(1,n);
    for(ll i = n-1 ; i >= 0; i--){
        tree.update(arr[i].ss.ss + 1,arr[i].ss.ff + tree.get(arr[i].ss.ss + 1,n));
    }
    cout<<tree.get(1,n);
}
