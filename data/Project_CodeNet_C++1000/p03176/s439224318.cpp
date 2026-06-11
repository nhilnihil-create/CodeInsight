#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=2e5+1;
vector<ll> a(N),h(N);
ll n;
vector<ll> dp(N);

struct dat{
    ll minm = 2e18;
    ll maxm = -minm;
    dat(){}//default constructor
    dat(ll val){//declare constructor
        minm = maxm = val;
    }
};

struct SegmentTree{
    vector<ll> arr;
    ll n;
    dat combine (const dat & l, const dat & r){//combine Left and Right child
        dat ret;
        ret.minm = min(l.minm, r.minm);
        ret.maxm = max(l.maxm, r.maxm);
        return ret;
    }
    vector<dat> tree;
    SegmentTree(vector<ll> &a){
        arr = a;
        n = a.size();
        tree.resize(4*n);
        build(1, 0, n-1);
    }
    SegmentTree(ll cap){
        n = cap;
        arr.resize(n, 0);
        tree.resize(4*n);
    }
    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = dat(arr[tl]);//see base conditions
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = combine(tree[v*2] , tree[v*2+1]);
        }
    }
    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            arr[pos] = new_val;//See update operations
            tree[v] = dat(arr[pos]);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }
    dat query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) 
            return dat();//See what to return
        if (l == tl && r == tr) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)) ,
            query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void update(ll pos, ll val){
        update(1, 0, n-1, pos, val);
    }
    dat query(ll l, ll r){
        return query(1, 0, n-1, l, r);
    }
};


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>h[i];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    SegmentTree st(dp);
    for(int i=0;i<n;i++){
        //for(int j=0;j<h[i];j++)
            //dp[h[i]]=max(dp[h[i]],a[i]+dp[j]);
        dat r=st.query(0,h[i]-1);
        st.update(h[i],a[i]+r.maxm);
    }
    cout<<st.query(0,n).maxm;


 
 
    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}