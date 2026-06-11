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
const int INF = 6e18;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,K; cin >> N >> K;
    int X[N],Y[N];
    rep(i,N){
        cin >> X[i] >> Y[i];
    }
    int ans=INF;
    rep(i,N){
        rep(j,N){
            rep(k,N){
                rep(l,N){
                    int a,b,c,d;
                    a=max({X[i],X[j],X[k],X[l]});
                    b=min({X[i],X[j],X[k],X[l]});
                    c=max({Y[i],Y[j],Y[k],Y[l]});
                    d=min({Y[i],Y[j],Y[k],Y[l]});
                    if(a==b || c==d) continue;
                    int cnt=0;
                    rep(n,N){
                        if(X[n]<=a && X[n]>=b && Y[n]<=c && Y[n]>=d){
                            cnt++;
                        }
                    }
                    if(cnt>=K){
                        chmin(ans,(a-b)*(c-d));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}