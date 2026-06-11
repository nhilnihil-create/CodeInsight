#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    REP(i,N) cin >> a[i];

    vector<ll> b;
    REP(i,N) {
        ll sum = 0;
        rep(j,i,N) {
            sum += a[j];
            b.push_back(sum);
        }
    }

    ll ans = 0;
    for(ll t = 40 ; t >= 1 ; t--){
        ll pt = pow(2,t-1);

        ll cnt = 0;
        bool flg = false;
        REP(i,b.size()){
            if(((ans + pt) & b[i]) == (ans + pt)) cnt++;
            if(cnt >= K) {
                flg = true;
                break;
            } 
        }
        if(flg) ans += pt;
    }

    pl(ans)

    return 0;
}