#include<bits/stdc++.h>
   
using namespace std;
  
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(14)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 
constexpr int MOD = 998244353;
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
   
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,k,x = 0,res = 0;
    cin >> n >> k;

    vector<int> a(n),cnt(64);
    rep(i,n){
        cin >> a[i];
        if(k == 0) res += 0 ^ a[i];
        int tmp = a[i];
        for(int i = 0;tmp;++i){
            cnt[i] += tmp & 1;
            tmp >>= 1;
        }
    }
    if(k == 0) return cout << res << '\n',0;
    for(int i = 40;i >= 0;--i){
        if(n - cnt[i] > cnt[i] && k >= x + (1ll << i)){
            x |= 1ll << i;
        }
    }
    rep(i,n){
        res += x ^ a[i];
    }
    cout << res << '\n';
    return 0;
}
    