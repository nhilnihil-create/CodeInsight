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
    int N;
    cin >> N;

    string c1[300], c2[300];;
    REP(i, N) cin >> c1[i];

    int ans = 0;
    REP(A, N) {
        REP(i, N) c2[i] = c1[(i - A + N) % N];

        bool flg = true;
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < j; i++) {
                if(c2[i][j] != c2[j][i]) {
                    flg = false;
                    break;
                }
                if(!flg) break;
            }
        }
        if(flg) ans += N;
    } 

    cout << ans << endl;

    return 0;
}
