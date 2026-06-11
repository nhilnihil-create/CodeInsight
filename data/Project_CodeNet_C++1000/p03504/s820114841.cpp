#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    vi d(100010,0);
    int N,C; cin >> N >> C;
    vc<pi> A[C];
    rep(i,N){
        int a,b,c; cin >> a >> b >> c;
        a--; b--; c--;
        A[c].eb(a,b);
        d[a]++;
        d[b+1]--;
    }
    rep(i,100010){
        d[i+1]+=d[i];
    }
    rep(i,C){
        sort(all(A[i]));
        rep(j,A[i].size()-1){
            if(A[i][j].se ==A[i][j+1].fi) 
                d[A[i][j].se]--;
        }
    }
    int ans=0;
    rep(i,100010){
        ans=max(ans,d[i]);
    }
    cout << ans << endl;
}