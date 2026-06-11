#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)
#define rrep(i,x) for(int i=(int)x-1;i>=0;--i)
#define rrep1(i,x) for(int i=(int)x;i>=1;--i)

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vpii=vector<pii>;

template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>p){os<<"("<<p.fst<<", "<<p.scd<<")";return os;}
template<class T>ostream&operator<<(ostream&os,const vector<T>v){rep(i,v.size()){if(i)os<<", ";os<<v[i];}return os;}
template<typename T>T&max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T&min(T&a,T&b){if(a < b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a < b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a > b){a=b;return true;}return false;}
constexpr ll TEN(ll n){return n==0?1:10ll*TEN(n-1);}

constexpr ll inf = TEN(9)+5;
constexpr ll linf = 3*TEN(18);

signed main()
{
    int N; cin >> N;
    vi x(N), y(N), h(N);
    rep(i, N) {
        cin >> x[i] >> y[i] >> h[i];
    }

    int idx = 0;
    rep(i, N) {
       if (h[i] != 0) idx = i; 
    }
    rep(cx, 101) rep(cy, 101) {
        int H = h[idx] + abs(x[idx] - cx) + abs(y[idx] - cy);

        if (H <= 0) continue;

        bool f = true;
        rep(i, N) {
            if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
                f = false;
            }
        }

        if (f) {
            printf("%d %d %d\n", cx, cy, H);
            return 0;
        }
    }
}
