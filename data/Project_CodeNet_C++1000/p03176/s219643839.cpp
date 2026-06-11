#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;


struct SegmentTree{
        int n;
        vector<ll> node;
        
        SegmentTree(vector<ll> v){
                int sz = v.size();
                n = 1;
                while(n < sz) n *= 2;
                node.resize(2*n-1,0);
                for(int i=0;i<sz;i++) node[i+n-1] = v[i];
                for(int i=n-2;i>=0;i--) node[i] = max(node[2*i+1],node[2*i+2]);
        }
        
        void update(int x,ll val){
                x += n-1;
                node[x] = val;
                while(x > 0){
                        x = (x-1)/2;
                        node[x] = max(node[2*x+1],node[2*x+2]);
                }
        }
        
        ll getmax(int a,int b,int k=0,int l=0,int r=-1){
                if(r < 0) r = n;
                if(r <= a || b <= l) return 0;
                if(a <= l && r <= b) return node[k];
                ll vl = getmax(a,b,2*k+1,l,(l+r)/2);
                ll vr = getmax(a,b,2*k+2,(l+r)/2,r);
                return max(vl,vr);
        }
};

int main(){
    int n;
    cin >> n;
    vector<ll> h(n),a(n),dp(n,0);
    rep(i,n){
        cin >> h[i];
        --h[i];
    }
    rep(i,n) cin >> a[i];
    SegmentTree segdp(dp);
    rep(i,n){
        ll now = segdp.getmax(0,h[i]) + a[i];
        segdp.update(h[i],now);
    }
    cout << segdp.getmax(0,n+1) << endl;
    return 0;
}