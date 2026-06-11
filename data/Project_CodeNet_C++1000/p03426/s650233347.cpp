//header{{{
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/math/common_factor_rt.hpp>
  
using namespace std;
using namespace boost::multiprecision;  
using namespace boost::math;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
//#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
inline int square(int a){ return a * a;}
inline int updiv(int a,int b){ return (a + b - 1) / b; }

constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
//}}}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w,d;
    cin >> h >> w >> d;

    vector<vector<int> > a(h,vector<int>(w)), cost(d+1);
    vector<pii> pos(h*w+1);

    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            pos[a[i][j]] = pii(i,j);
        }
    }

    reps(i,d){
        for(int j = i; j <= h*w; j += d){
            if(j == i){
                cost[i].emplace_back(0);
            }else{
                int tmp = abs(pos[j-d].first - pos[j].first) + abs(pos[j-d].second - pos[j].second);
                int pos = j - i;
                cost[i].emplace_back(cost[i][pos/d-1] + tmp);
            }
        }
    }

    int q;
    cin >> q;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        int sub = updiv(l,d) - 1;
        int s = l % d;
        if(s == 0) s = d;
        int g = (r - s) / d;
        cout << cost[s][g] - cost[s][sub] << '\n';
    }

    return 0;
}
