#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define PER(i,n) for (int i=(N-1);i>=0;--i)
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

const ll longinf = 1LL << 60 ;

int main() {
    int N;
    cin >> N;

    vector<ll> a(N + 1, 0);
    REP(i, N) {
        int val;
        cin >> val;
        a[i + 1] = a[i] + val;
    }

    ll ans = longinf;
    int m1 = 1, m2 = 3;
    for(int x = 2; x <= N - 2; x++){

        bool flg1 = true;
        while(flg1) {
            ll g1 = abs((a[x] - a[m1]) - a[m1]);
            ll g2 = abs((a[x] - a[m1 + 1]) - a[m1 + 1]);

            if(g1 <= g2) flg1 = false;
            else m1++;
        }

        bool flg2 = true;
        while(flg2) {
            ll g1 = abs((a[N] - a[m2]) - (a[m2] - a[x]));
            ll g2 = abs((a[N] - a[m2 + 1]) - (a[m2 + 1] - a[x]));

            if(g1 <= g2) flg2 = false;
            else m2++;
        }

        ll s1 = a[m1];
        ll s2 = a[x] - a[m1];
        ll s3 = a[m2] - a[x];
        ll s4 = a[N] - a[m2];

        chmin(ans, max({s1, s2, s3, s4}) - min({s1, s2, s3, s4}));
    }

    cout << ans << endl;

    return 0;
}