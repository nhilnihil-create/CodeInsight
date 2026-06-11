


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;


const int mod=1000000007;
//const int mod=998244353;

struct segtree {
    struct node{
        long long int min,max,sum;
    };
    vector<node> st;
    long long int ans=0;
    int n;
    template<typename M>
    segtree(M a){
        n=a;
        st.resize(4*n);
    }
    
    void combine(node &a,node &b,node &c){
        a.sum=b.sum+c.sum;
        a.min=min(b.min, c.min);
        a.max=max(b.max,c.max);
    }
    template <typename M>
    void build(int v,int l,int r, vector<M> &vec){
        if (l==r) {
            st[v].max=vec[l];
            st[v].min=vec[l];
            st[v].sum=vec[l];
        }
        else{
            int m=(l+r)/2;
            build(2*v, l, m ,vec);
            build(2*v+1, m+1, r , vec);
            combine(st[v], st[2*v], st[2*v+1]);
        }
    }
    node query(int v,int l,int r,int l_,int r_){
        if (l==l_&&r==r_) {
            return st[v];
        }
        int m=(l+r)/2;
        if (r_<=m) {
            return query(2*v, l, m, l_, r_);
        }
        else if (l_>m){
            return query(2*v+1, m+1, r, l_, r_);
        }
        else{
            node a,b,c;
            b=query(2*v, l, m, l_, m);
            c=query(2*v+1, m+1, r, m+1, r_);
            combine(a, b, c);
            return a;
        }
    }
    template <typename M>
    void update(int v,int l,int r,int id,M val){
        if (l==r) {
            st[v].min=val;
            st[v].max=val;
            st[v].sum=val;
            return;
        }
        int m=(l+r)/2;
        if (id<=m) {
            update(2*v, l, m, id, val);
        } else {
            update(2*v+1, m+1, r, id, val);
        }
        combine(st[v], st[2*v], st[2*v+1]);
    }
    long long int query(int l,int r){
        return query(1, 0, n-1, l, r).max;
    }
    template <typename M>
    void update(int id, M val){
        update(1, 0, n-1, id, val);
    }
    
};



int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,d,y,l,r;
    cin >> n;
    vll hh(n),bb(n);
    for(int i=0; i<n; i++){
        cin >> hh[i];
    }
    b=0;
    for(int i=0; i<n; i++){
        cin >> bb[i];
        b+=bb[i];
    }
    segtree st(n+10);
    c=0;
    for(int i=0 ; i<n; i++){
        a=st.query(0,(int)hh[i]);
        c=max(a+bb[i],c);
        st.update((int)hh[i],a+bb[i]);
    }
    cout << c << el;
    
    
    return 0;
}
