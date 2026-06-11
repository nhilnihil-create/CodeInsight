#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) <<

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


class SegmentTree{
public:
    ll N;
    vector<ll> dat;
    ll INF = (1ll<<31);

public:
    SegmentTree(vector<ll> v){
        int sz = v.size();
        N = 1; 
        while(N < sz) N *= 2;
        dat.resize(2 * N - 1);
        for(int i = 0; i < sz; ++i) dat[i+N-1] = v[i];
        for(int i = N-2; i >= 0; --i) dat[i] = __gcd(dat[2*i+1], dat[2*i+2]);
    }

    void update(int i, ll x){
        i += N -1;
        dat[i] = x;
        while(i > 0){
            i = (i - 1) / 2;
            dat[i] = __gcd(dat[i*2+1],dat[i*2+2]);
        }
    }

    ll query(int a, int b, int k, int l, int r){
        if(a <= l && r <= b) return dat[k];
        else if(r <= a || b <= l) return INF;
        else{
            ll c1 = query(a, b, 2*k+1,l,(r+l)/2);
            ll c2 = query(a, b, 2*k+2,(r+l)/2, r);
            return __gcd(c1, c2);
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    SegmentTree tree(a);


    ll ans = 0;
    for(int i = 1; i < n-1; i++){
        tree.update(i-1,a[i-1]);
        tree.update(i,a[i+1]);
        ans = max(ans,tree.dat[0]);
    }
    
    tree.update(n-2,a[n-2]);
    tree.update(0,a[1]);
    ans = max(ans, tree.dat[0]);
    tree.update(0,a[0]);
    tree.update(n-1,a[n-2]);
    ans = max(ans, tree.dat[0]);

    cout << ans << endl;
}
